
# Sapient Release Notes

!!! danger "Feedback, Suggestions, & Feature Requests Welcomed! &nbsp; 🤗"

**Version:** 0.0.4  

**Release Date:** Feb 20, 2025  

## Summary

*Sapient has been upgraded with enhanced project analysis capabilities and an improved user experience. Users can now engage in ongoing conversations with Sapient to refine plans, request modifications, or continue implementations seamlessly. The interactive interface has been streamlined, and Confirmation Mode has been deprecated for a more intuitive experience.*

## What’s New? ✨

!!! tip "Enhanced Project Analysis 🛠️"
Sapient now comprehensively analyzes all components of a project, including assets, code, and project settings.

!!! tip "Revamped User Experience 🎨"
The interface has also been simplified to provide a chat-like user experience for better user<>sapient collaboration. Additionally, **Confirmation Mode** has been deprecated to enhance workflow efficiency, allowing for a more seamless interaction with Sapient.

## Improvements 🎉

!!! success "Sapient Asset Architect Improvements"
    - Sapient now deeply understands **Behavior Trees** and **Blueprints**.
    - Enhanced recognition of **C++ to Blueprint references** across projects.

!!! success "User Interface Improvements"
    - **Deprecated:** Confirmation Mode in favor of a more seamless, interactive experience.
    - **New:** Extended conversation support for deeper interactions, allowing for follow-ups, clarifications, and iterative refinements.

## Bug Fixes 🪲

??? bug "Fixed Confirmation Mode Replacement"
    - Replaced Confirmation Mode with **Interactive Mode** for a more robust user experience.

??? bug "Enhanced Conversation Flow"
    - Improved Sapient’s ability to sustain longer conversations without losing context.

## Known Issues 🚧

!!! warning "Sensitivity to User Prompts ⚠️"
    - Sapient’s performance can degrade when prompts contain typos, incorrect grammar, or are too vague.

!!! warning "Asset Architect Handling 🏗️"
    - Users have reported better results when using **clear, human-understandable** terminology for Asset Architecture requests.

!!! warning "Conversation Length Limits 🕰️"
    - Conversations can now continue much longer; however, Sapient has a **memory limit** beyond which requests may fail.
    - **Workaround:** Clicking **“End”** and starting a new conversation resets Sapient’s memory.

## How to Update ⚙️

To update, please navigate to the [Sapient Unreal Engine Github repository](https://github.com/sapient-technology/sapient-unreal) and either:

1. Run `git pull` from the **Windows** `cmd line` or **Mac** `terminal window`.
2. [Download](https://github.com/sapient-technology/sapient-unreal/archive/refs/heads/main.zip) the files manually and follow the [installation instructions](https://upgraded-chainsaw-v7enkml.pages.github.io/installation/#game-engine-integration).

## Feedback 🗣️

We’d love to hear your thoughts! If you encounter issues or have feedback or suggestions for new features, please reach out on [Discord](https://discord.gg/cv2TCNdM)! 🚀

---

**Version:** 0.0.3  

**Release Date:** Feb 4, 2025  

## Summary

*Sapient now understands Behavior Trees and better recognizes C++ to Blueprint references, improving project navigation. It also locates C++ components in Blueprints more efficiently. UI updates enhance readability with clearer messaging and improved font styling. Bug fixes include resolving Confirmation Mode and storage-related issues, though some known issues remain, such as occasional auto-implementation bias. Users can mitigate this by enabling Confirmation Mode or specifying "do not implement anything." For better Asset Architecture handling, clear, human-readable terms are recommended. These updates make Sapient more intuitive and efficient for development teams.*

## What’s New? 👀

!!! tip "Understanding Behavior Trees & C++ to Blueprint References 🚀"
Sapient has been upgraded with a foundational understanding of Behavior Trees and enhanced recognition of C++ to Blueprint references across projects. Its ability to locate specific C++ components within Blueprints has also been improved, streamlining development workflows.

!!! tip "Improved UI – Better Readability & Messaging 🎨"
Updated the user interface with clearer messaging and refined font styling for better readability and consistency.

## Improvements 🎉

!!! success "Sapient Asset Architect Improvements"
    - Sapient now has a basic understanding of Behavior Trees.
    - Improved Sapient’s ability to understand C++ to Blueprint references across projects.

!!! success "Sapient Code Architect Improvements"
    - Improved ability for Sapient to locate specific C++ components used in Blueprints.

!!! success "User Interface Improvements"
    - Improved Sapient messaging for better clarity and consistency.
    - Enhanced font styling for better readability.

## Bug Fixes 🪲

??? bug "Fixed Confirmation Mode"
    - Fixed bug where "confirm before implementation" broke for certain users.
  
??? bug "Fixed Storage Bug"
    - Some user requests were failing due to data constraints.

## Known Issues 🚧

!!! warning "Auto Implementation Bias"
    - Sapient at times will be biased toward implementing requests even if unclear.
    - **Recommendation Usage Patterns:**
      - For Code or Asset queries, use "Confirmation Mode."
      - Or explicitly add "do not implement anything" to queries.

!!! warning "Asset Architect Handling"
    - Users reported that using "human-understandable" terms helps the Asset Architecture when handling requests.

## How to Upgrade ⚠️

To update, please navigate to the [Sapient Unreal Engine Github repository](https://github.com/sapient-technology/sapient-unreal) and either:

1. `git pull` from the **Windows** `cmd line` or **Mac** `terminal window`
2. [Download](https://github.com/sapient-technology/sapient-unreal/archive/refs/heads/main.zip) the files to your local then follow the [installation instructions](https://fuzzy-chainsaw-9p658wm.pages.github.io/installation/#game-engine-integration).

## Feedback 🗣️

We’d love to hear your thoughts! If you encounter issues or have feedback or suggestions for new features, please do not hesitate to tell us on [Discord](https://discord.gg/cv2TCNdM)!  

---

# Sapient Release Notes

!!! danger "Feedback, Suggestions, & Feature Requests Welcomed! &nbsp; 🤗"

**Version:** 0.0.2

**Release Date:** Jan 25, 2025

## Summary

*Sapient now supports prototyping, building, and shipping Unreal Engine games using Blueprints, with operations like reading, modifying, and creating Blueprints (Alpha release for enterprise testing—feedback encouraged). Improved UI with better output readability, smoother runtime task handling, and resolved bugs for compilation, shipping builds, and HTTP connectivity.*

## What’s New? 👀

!!! tip "Feature Launch – Sapient Asset Architecture for Blueprints &nbsp; 🚀"
Sapient can now help game developers prototype, build, and ship games that rely on Blueprints. As a reminder, [Blueprints](https://dev.epicgames.com/documentation/en-us/unreal-engine/blueprints-visual-scripting-in-unreal-engine) are a no-code visual scripting in Unreal Engine that allows users to create gameplay elements. Sapient supports operations such as reading, modifying, and creating Blueprints. See the examples in our docs via [Sapient Unreal Engine Asset Architect](https://fuzzy-chainsaw-9p658wm.pages.github.io/getting-started/#coming-soon-unreal-engine-asset-architect). 

??? warning "Alpha Release"
    This feature is available as an early “Alpha” release for testing from enterprise customers. Given it remains in active development, your feedback on ways to improve it is immensely important.  

!!! tip "Improved UI – Smoother User Experience &nbsp; 🏄"
Improved Sapient output readability with better spacing and removed "processing messages" during runtime task handling for a smoother user experience.

## Improvements 🎉
!!! success "Sapient Asset Architect for Blueprints"
    - Enabled the ability to read properties from Blueprints
    - Enabled the ability to modify or update properties of Blueprints
    - Support for Blueprint Classes & Assets
    - Enabled the ability to create Blueprints from other Blueprints, from C++ classes, and C++-derived Blueprints
    - ⚠️ *We recommend users using Asset Architect on **Confirmation Mode***
  
!!! success "User Interface Improvements" 
    - Output Readability → better spacing for improved readability
    - Processing Notifications → removed “processing messages” while handling tasks
    - Code Changes → Sapient now shows all code changes after completion
  
!!! success "Updated Docs"
    - Added “how-to” install Sapient for not Git users
    - Added tips & best practices for using Sapient with Perforce

## Bug Fixes 🪲
??? bug "Fixed Compilation Bug"
    - Fixed bug that required Editor restart after code changes
  
??? bug "Fixed Shipping Build Bug" 
    - Fixed bug that broke builds due to ship vs dev flags
  
??? bug "Fixed HTTP Connectivity Requiring Double Requests"
    - Requests would hang or require sending requests twice to Sapient

## Known Issues 🚧
??? warning "BluePrint “undo” Functionality"
    - Support for undoing changes of Blueprint modifications is still in development. User have to manually undo changes.
??? warning "Prompting Sapient Code Architect"
    - Sapient can get confused by ambiguous or vague requests, leading to implementation errors
    - We recommend using Sapient in **confirmation mode** or checking code correctness after completion


## How to Upgrade ⚠️

To update, please navigate to the [Sapient Unreal Engine Github repository](https://github.com/sapient-technology/sapient-unreal) and either:

1. `git pull` from the **Windows** `cmd line` or **Mac** `terminal window`
2. [Download](https://github.com/sapient-technology/sapient-unreal/archive/refs/heads/main.zip) the files to your local then follow the [installation instructions](https://fuzzy-chainsaw-9p658wm.pages.github.io/installation/#game-engine-integration) 
   
## Feedback 🗣️

We’d love to hear your thoughts! If you encounter issues or have feedback or suggestions for new features, please do not hesitate to tell us on [Discord](https://discord.gg/cv2TCNdM)!  

