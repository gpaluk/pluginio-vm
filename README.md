# Plugin.IO VM!

Hi! Welcome to **Plugin.IO VM**, a community project aimed at porting **AVM2** to **HTML5** using C++ and **Emscripten**.


# Background

After making a case for a rich media **binary format**, we set out to develop a new **HTML5** virtual machine specification to provide bindings for both **Canvas** and **WebGL**. To ensure best performance and portability we decided to adopt the **Emscripten C++ compiler** toolchain. 

It was imperative that we support rich **animations**, a complete **scripting language** and support **simple distribution** methods. It became clear that porting the **AVM2** runtime would allow this whilst also enabling a historical wealth of **Adobe Flash** content for modern **Desktop** and **Mobile Web** browsers, which have discontinued the **NPAPI** and **PPAPI** plugin APIs.
