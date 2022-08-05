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
* \brief Definition of Tagging Example Visualization Measurement Object 
* \author Christopher Maneth
* \copyright (C)2015-2022 b-plus technologies GmbH
* \date 18.05.2022
* \version 2.4.240
*
******************************************************************************/

// Suppress the deprecated use of the codecvt library for C++17 and Visual Studio.
#define _SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING

// Suppress the deprecated use of the filesystem library for c++14 and Visual Studio 2019.
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING

// Product information
#pragma once
#define VERSIONINFO_PRODUCT             "Tagging Example"
#define VERSIONINFO_AUTHOR              "Christopher Maneth"
#define VERSIONINFO_COMMENTS            ""

// Version information
#define VERSIONINFO_VERSION             2.4
#define VERSIONINFO_BUILD               240
#define VERSIONINFO_SUBBUILD            0

#if defined(_MSC_VER)
#	define NOMINMAX
	#include <windows.h>
#endif

#include <Core/AvCore.h>
#include <Visual/Support/AvVisMeasObj.h>
#include <App/AvApp.h>
#include <App/AvApp.RecorderControl.h>


class CTaggingExampleVisObject : public AvVis::CAvetoVisMeasObject
{
public:
	CTaggingExampleVisObject() = default;

	~CTaggingExampleVisObject() = default;

	DECLARE_OBJECT_CLASS_NAME("Tagging Example")
	DECLARE_OBJECT_GROUP_ASSOC(AVETO::Core::g_szGroupGeneric)

	// Connector map
	BEGIN_AVETO_CONNECTOR_MAP()
	END_AVETO_CONNECTOR_MAP()

	// Property map
	BEGIN_AVETO_PROPERTY_MAP()
		AVETO_PROPERTY_CHAIN_BASE(AvVis::CAvetoVisMeasObject)
	END_AVETO_PROPERTY_MAP()
	   
	/**
	 * \brief Initialization function called when an instance of this class is created.
	 * \return Returns true if the initialization was successful, false if it failed.
	 */
	bool OnCreate() override;

	/**
	 * \brief Paints the UI of a instance of this class.
	 * \param[in] rPainter A painter object to draw the UI.
	 */
	void OnPaint(AvVis::CAvPainter& rPainter) override;

	/**
	* \brief Creates a tag by calling the recorder control service set marker function
	*/
	void CreateTag();

private:
	
	AvVis::CAvButton										m_ButtonCreateTag;			//!< User button for create a new tag
	AvVis::CAvInput											m_InputTextDescription;		//!< User text input for description 
	AvVis::CAvLogWindow										m_LogWindow;				//!< Log windows for displaying errors and successes 
	
	AVETO::Core::Support::IObjectPtr						m_ptrControlService;		//!< Pointer to recording control service
	AVETO::App_v240::ILocalRecorderStatus*					m_pRecorderStatus;			//!< Interface cache for recorder status interface
	AVETO::App_v240::ILocalRecorderCommand*					m_pRecorderCommand;			//!< Interface cache for recorder command interface
};

DEFINE_AVETO_OBJECT(CTaggingExampleVisObject)
