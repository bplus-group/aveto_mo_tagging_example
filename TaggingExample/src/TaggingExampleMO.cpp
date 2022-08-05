/******************************************************************************/
/*! \file
*
* \verbatim
******************************************************************************
*                                                                            *
*    Copyright (c) 2015-2022, b-plus technologies GmbH.                      *
*                                                                            *
*    All rights are reserved by b-plus technologies GmbH.                    *
*    The Customer is entitled to modify this software under his              *
*    own license terms.                                                      *
*                                                                            *
*    You may use this code according to the license terms of b-plus.         *
*    Please contact b-plus at services@b-plus.com to get the actual          *
*    terms and conditions.                                                   *
*                                                                            *
******************************************************************************
\endverbatim
*
* \brief Implementations of Tagging Example Visualization Measurement Object 
* \author Christopher Maneth
* \copyright (C)2015-2022 b-plus technologies GmbH
* \date 18.05.2022
* \version 2.4.240
*
******************************************************************************/

#include "TaggingExampleMO.h"

bool CTaggingExampleVisObject::OnCreate()
{
	SetFlags(GetFlags() | AVETO::Visual::EWindowFlags::no_save_settings);
	SetSize({ 500, 320 });

	bool bRet = m_ButtonCreateTag.Create(this, "Create Tag", std::bind(&CTaggingExampleVisObject::CreateTag, this));
	bRet &= m_InputTextDescription.Create(this, "Description", -1, R"({"source:": "Tagging Example"})", true);
    bRet &= m_LogWindow.Create(this, "Log window");

    m_LogWindow.SetShow(true);

    m_ptrControlService = AvCore::GetService("Recorder Control Service");
    if (m_ptrControlService)
    {
        m_pRecorderStatus = m_ptrControlService.GetInterface<AVETO::App_v240::ILocalRecorderStatus>();
        m_pRecorderCommand = m_ptrControlService.GetInterface<AVETO::App_v240::ILocalRecorderCommand>();
    }

	return bRet;
}

void CTaggingExampleVisObject::OnPaint(AvVis::CAvPainter& rPainter)
{
	rPainter << m_ButtonCreateTag;
	rPainter << AvVis::SNewLine();
	rPainter << m_InputTextDescription;
	rPainter << AvVis::SNewLine();
	rPainter << m_LogWindow;
}

void CTaggingExampleVisObject::CreateTag()
{
    if (!m_pRecorderStatus || !m_pRecorderStatus || !m_pRecorderCommand)
    {
        m_LogWindow.Add("Recorder control service is not available", AVETO::Visual::ELogType::Error);
        return;
    }

    const auto sStatus = m_pRecorderStatus->GetStatus();
    if (sStatus.EConnectionState != AVETO::App_v240::ILocalRecorderStatus::EConnectionState::RecorderServiceRunning)
    {
        m_LogWindow.Add("Recorder is not running", AVETO::Visual::ELogType::Error);
        return;
    }

    if (!m_pRecorderCommand->SetMarker(m_InputTextDescription.GetValueText().c_str()))
    {
        m_LogWindow.Add("Creating tag failed", AVETO::Visual::ELogType::Error);
        return;
    }

    m_LogWindow.Add("Tag created successfully", AVETO::Visual::ELogType::Info);
}
