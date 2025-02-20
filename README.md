# TCG_Sample
- Turn based Card Game on Unreal Engine

## Dependencies
- Unreal Engine 5.5
- clang(maybe)

## Compile Tutorial
- Idk

# What I am doing to this
With this pull request, I'd like to 

## #define TMP_NAME
> This is for convenience/safe.  
> It will help making the shape of declaration and definition of class methods.  
> Example would be following:

```cpp
#define TMP_NAME
class A {
    int TMP_NAMESPACE returns3(); // This is a function
};
#undef TMP_NAME

// hint for telling following functions are methods.
#define TMP_NAME A::

// By the same shape, returns3 will be automatically searched.
int TMP_NAME returns3() {
    return 3;
}
```
## Private/_imp.h
> This is for convenience/safe.  
> Including it will automatically disable the class method decorators which are not necessary for implementing methods,  
> preventing the miscompile from using them.

> Two keywords are disabled for now: 
- virtual
- override