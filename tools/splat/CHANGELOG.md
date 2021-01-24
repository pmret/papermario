# splat Release Notes

## 0.5
* n64splat name changed to splat
  * Some refactoring was done to support other platforms besides n64 in the future 
    * New `platform` option, which defaults to `n64`
  * This will cause breaking changes in custom segments, so please refer to one of the changes in one of the n64 base segments for details
* Support for custom artifact paths 
  * New `undefined_syms_auto_path` option
  * New `undefined_funcs_auto_path` option
  * New `cache_path` option
  * (All path-like options' names now end with `_path`)
