!!! warning "**Active Development**"
    - Sapient is in active development with closed use only for strategic partners. 
    - Please report any issues to help us make it better for you and those who follow!

## System Requirements

To use the Sapient Plugin, ensure your system meets the following requirements:

=== "Unreal Engine"
    !!! abstract "Requirements"
        - **Engine Version**
            - Version 5 or higher
            - Refer to the [Unreal Engine Documentation](https://docs.unrealengine.com/) for detailed system requirements.
        - **C++ Version**
            - Version 17 or higher.
        - **Operating System**
            - Windows 10 or later or macOS 10.15 or later, or a recent Linux distribution.
        - **Version Control**
            - Git-based version control for project e.g. Github, Perforce, etc.

=== "Unity"
    !!! abstract "**Coming Soon**"



## API Keys & Github Access

The Sapient Plugin requires API Access keys for each user. These keys are issued at the enterprise level.

!!! abstract "**API Keys**"
    - If you do not have an API key, please contact the Sapient admins on your company's private [Discord channel](https://www.discord.com/sapient).

!!! abstract "**Github Access**"
    - The Sapient Plugin is hosted in a **private [Github repository](https://github.com/sapient-technology/sapient-unreal)**. Ensure you have the necessary access permissions.
    - If you do not have access, request it from your project administrator or contact the Sapient admins on your company's private [Discord channel](https://www.discord.com/sapient).


## Game Engine Integration

Sapient integrates directly into your game engine. Follow the steps below for your specific engine:

=== "Unreal Engine"
    !!! abstract "Step 1: Download Sapient Plugin"
        Clone Sapient UE Plugin from Github
        ```cmd
            git clone https://github.com/sapient-technology/sapient-unreal.git
        ```
    !!! Tip "Non-Git or Perforce Users"
        You can [download](https://github.com/sapient-technology/unreal-playlab/archive/refs/heads/main.zip) Sapient plugin files as a ZIP file from the Github repo then continue with steps below!
        ```cmd
        1. Navigate to Github
        2. Click [Code](https://github.com/sapient-technology/unreal-playlab/archive/refs/heads/main.zip) > [Download ZIP](https://github.com/sapient-technology/unreal-playlab/archive/refs/heads/main.zip)
        ```
      ---
    !!! abstract "Step 2: Add Sapient as Project Plugin"
        Copy the plugin files to your game engine's plugin directory.
        ```cmd
            mv sapient-unreal MyProject\Plugins
        ```
    !!! Tip
        Alternatively you can clone the repo directly into your MyProject\Plugins directory
        ```cmd
        cd MyProject\Plugins && git clone https://github.com/sapient-technology/sapient-unreal.git
        ```
    ---
    !!! abstract "Step 3: Enable Plugin"
        Open Unreal Engine Editor, navigate to the plugin settings to enable Sapient.  
        ```cmd
        Unreal Engine Editor >> Edit > Plugins > Sapient > Click [Checkbox] to Enable
        ```
    !!! abstract "Step 4: Add Plugin API Key"
        Open Unreal Engine Editor and navigate to the Project settings to enter API key.  
        ```cmd
        Unreal Engine >> Edit > Project Settings > Sapient > Enter API Key
        ```
    ---
    !!! abstract "Step 5: Restart Editor & Verify Installation"
        Restart your game engine. Sapient will appear in your Editor `window`.  
        ```cmd
        Unreal Engine >> Window > Sapient
        ```

=== "Unity"
    !!! abstract "**Coming Soon**"

## Troubleshooting

If you encounter issues during installation or usage of the Sapient Plugin, try the following steps:

1. **Check System Requirements**
   - Ensure your system meets the minimum requirements listed in the [System Requirements](#system-requirements) section.

2. **Verify API Key**
   - Ensure your API key is correctly entered in the plugin configuration.

3. **Check Github Access**
   - Verify that you have access to the **Sapient [Github repository](https://github.com/sapient-technology/sapient-unreal)**.

4. **Review Documentation**
   - Refer to the [UE Documentation](https://docs.unrealengine.com/) for additional help.

5. **Contact Support**
   - If the issue persists, check [#community-support](https://discord.com/invite/your-invite-code) or contact Sapient admins on [Discord](https://www.discord.com/sapient).