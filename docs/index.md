# Ymp Source Code Documentation

## Introduction
This project is structured to facilitate the development and management of a software application. Below is an overview of the directory structure and the purpose of each directory.

## Project Structure

- **core**: Contains the core components of the application, including the command-line interface, interpreter, logger, operations, and variable management.

- **data**: Responsible for handling data-related functionalities such as building, managing dependencies, and package management.

- **operations**: Divided into two subdirectories:
  - **package-manager**: Contains functionalities related to package management, including building, installing, and listing packages.
  - **utility**: Provides utility functions for printing and managing set/get operations.

- **start**: Contains assembly files for different architectures (aarch64, arm, i686, x86_64) to support platform-specific initialization.

- **utils**: A collection of utility functions and modules for various tasks such as error handling, file operations, string manipulation, and YAML processing.

- **ctx.c.in**: A template file that may be used for context-related configurations or initializations.

## YMP Data Structure
The YMP data structure consists of:
- **Package**: Represents individual software packages.
- **Repository**: Contains available packages.
- **YMP Build**: Manages the build process for packages.
- **Dependency**: Manages package dependencies.
- **Quarantine**: Holds packages that are not ready for installation.

## Components
- **YMP CLI**: Command-line interface for managing packages and operations.
- **YMP Shell (ympsh)**: Interactive shell for executing YMP commands.
- **YMP Operation Manager**: Core component that handles operations such as install, remove, build, and index.

