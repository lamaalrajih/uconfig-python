# uconfig-python
Python bindings for uConfig https://github.com/Robotips/uConfig

## Development Roadmap

Below is the agreed-upon plan for turning **uconfig-python** into a publishable Python package while retaining the existing C++ core and enabling pure-Python extensions.

### 1. Repository layout
```
uconfig-python/
├── uConfig/                ← git submodule → upstream C++ project
├── bindings/               ← pybind11 glue code (.cpp / .hpp)
├── pyuconfig/              ← pure-Python layer & helpers
│   ├── __init__.py
│   └── helpers.py
├── CMakeLists.txt          ← drives C++ build + bindings
├── pyproject.toml          ← PEP 517 build via scikit-build-core
├── README.md, LICENSE
├── .gitignore, .gitattributes
└── .github/workflows/      ← CI building wheels with cibuildwheel
```

### 2. Toolchain choices
* **Bindings:** `pybind11`
* **Build backend:** `scikit-build-core` (modern CMake-based)
* **Wheel builder:** `cibuildwheel`
* **Tests:** `pytest`

### 3. Phase-by-phase plan
| Phase | Goals |
|-------|-------|
| **0 – Preparation** | Add `uConfig` as git submodule; list C++ APIs to expose. |
| **1 – Build scaffold** | Create `pyproject.toml`, `CMakeLists.txt`, minimal `bindings/module.cpp`; confirm `import pyuconfig` works. |
| **2 – API surface** | Expose core classes via pybind11; add Pythonic wrappers in `pyuconfig/`. |
| **3 – Testing & CI** | Write pytest suite; add GitHub Actions + cibuildwheel. |
| **4 – Packaging & Docs** | Finalise `__init__.py`, README, badges; create release wheels. |
| **5 – Publish & Governance** | Upload to PyPI; add `CONTRIBUTING.md`, document how to add Python-only features. |

### 4. Adding new Python-only features
Develop new functionality directly inside `pyuconfig/` using the bound C++ classes. Prototype in Python first; optimise later in C++ if needed.

### 5. Next immediate steps
Now that the scaffold successfully builds and `import pyuconfig` works, the short-term tasks are:

1. **Expose a real C++ API call** – decide which uConfig class/function to bind first (e.g. `Lib` loader) and add it in `bindings/`.
2. **Add tests** – create `tests/test_basic.py` asserting that `pyuconfig.version()` returns a non-empty string.
3. **CI setup** – add a GitHub Actions workflow running `pytest` and building wheels via `cibuildwheel`.
4. **Wheel housekeeping** – bump the stub version in `bindings/module.cpp` when real APIs land; update `__init__.py` accordingly.
5. **Docs** – extend this README with an install snippet and a “Hello World” example once the first API is exposed.