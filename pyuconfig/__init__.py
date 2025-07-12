"""
High-level Python package that re-exports the native bindings.

Public API:
    version() -> str
"""

from ._pyuconfig import version  # type: ignore[attr-defined]

__all__ = ["version"]