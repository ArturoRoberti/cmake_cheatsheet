# Make sure to "source" this script or ~/.bashrc to
# retain the change to PYTHONPATH in the current session

# Uninstall any existing package
pip uninstall example_py -y

# Install via pip
pip install -e .

# Set PYTHONPATH in .bashrc (if not already set)
BUILD_DIR="$(pwd)/build"
if [[ ":$PYTHONPATH:" != *":$BUILD_DIR:"* ]]; then
    export PYTHONPATH=$BUILD_DIR:$PYTHONPATH
    echo "export PYTHONPATH=\"$BUILD_DIR:\$PYTHONPATH\"" >> "$BASHRC"
fi
