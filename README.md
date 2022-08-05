<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://www.b-plus.com/de/home">
    <img src="https://www.b-plus.com/fileadmin/data_storage/images/b-plus_Logo.png" alt="Logo" width="150" height="150">
  </a>
  
  <h3 align="center">AVETO.app Tagging Example Measurement Object</h3>

  <p align="center">
    Measurement object for AVETO.app Visualization to demonstrate the tagging functionality
    <br />
    <a href="#usage">View Usage</a>
    ·
    <a href="https://github.com/bplus-group/aveto_mo_tagging_example/issues">Report Bug</a>
    ·
    <a href="https://github.com/bplus-group/aveto_mo_tagging_example/issues">Request Feature</a>
  </p>
</div>
<br />

<!-- PROJECT SHIELDS -->
<div align="center">

  [![LinkedIn][linkedin-shield]][linkedin-url]
  [![Stars][star-shield]][star-url]

</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
  </ol>
</details>

---

## About The Project

**Object:** Visualization Object  
**Name:** Tagging Example  

After creation, a small user interface is displayed that allows you to create tags with a mouse click. The JSON description of the tag can be customized via a text field.

<p align="right"><a href="#top">Back to top</a></p>

## Getting Started

Clone this repository and make sure you fulfill following requirements

### Prerequisites

- Installed AVETO.app >= 2.5.0
- Set AVETO_SDK_PATH as environment variable which by default points to the folder `C:\Program Files\b-plus\AVETO.app\sdk`
- Installed Windows SDK-Version 10.0.17763.0

<p align="right"><a href="#top">Back to top</a></p>

### Installation

1. Install AVETO.app
2. Clone the repo
   ```sh
   git clone https://github.com/bplus-group/aveto_mo_tagging_example.git
   ```
5. Build the project
6. Copy TaggingExample.dll to your AVETO MO directory (default: `%USERPROFILE%\Documents\AVETO\measobj\`)

<p align="right"><a href="#top">Back to top</a></p>

## Usage

Right-click in the node graph editor of the configuration manager and choose *Visualization Objects -> Tagging Example* as seen below.

![taggingexample][taggingexample]

By pressing the *Create Tag* button a new tag can be created. The JSON description of the tag can be customized using the *Description* text field.

![taggingexample_ui][taggingexample_ui]

<p align="right"><a href="#top">Back to top</a></p>

## Contributing


If you have a suggestion that would improve this, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".  
Don't forget to give the project a star! Thanks again!


1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/NewFeature`)
3. Commit your Changes (`git commit -m 'Add some NewFeature'`)
4. Push to the Branch (`git push origin feature/NewFeature`)
5. Open a Pull Request

<p align="right"><a href="#top">Back to top</a></p>

## License

Check License information. See `LICENSE` for more information.

<p align="right"><a href="#top">Back to top</a></p>








<!---Links And Images -->
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&color=808080
[linkedin-url]: https://de.linkedin.com/company/b-plus-group
[star-shield]: https://img.shields.io/github/stars/bplus-group/aveto_mo_tagging_example.svg?style=for-the-badge&color=144E73&labelColor=808080
[star-url]: https://github.com/bplus-group/aveto_mo_tagging_example
[taggingexample]: ./docs/images/taggingexample.png "Tagging Example"
[taggingexample_ui]: ./docs/images/taggingexample_ui.png "Tagging Example UI"
