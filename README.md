

<h1>Image to ASCII Converter Using <code>stb_image</code> Library</h1>

<h2>Introduction</h2>
<p>This project uses the <code>stb_image</code> library to load and save images in C. The goal is to convert images into ASCII art.</p>

<h2>Steps</h2>

<h3>1. Loading an Image</h3>
<p>The goal is to get the image's pixels and load it into memory.</p>
<p><strong>How to load an image:</strong></p>
<pre><code>stbi_load(char *img_path, int *width, int *height, int *channels, 0);</code></pre>
<ul>
    <li><code>img_path</code>: Path to the image file.</li>
    <li><code>width</code>, <code>height</code>: Dimensions of the image.</li>
    <li><code>channels</code>: Number of pixel values (RGB or RGBA).</li>
    <li><code>0</code>: Load only RGB, ignoring the alpha channel.</li>
</ul>

<h3>2. Compiling the Code</h3>
<p>Use this command to compile:</p>
<pre><code>gcc main.c -o main -lm</code></pre>

<h3>3. Saving an Image</h3>
<p>After editing, save the new version to disk.</p>
<p><strong>How to save an image:</strong></p>
<pre><code>stbi_write_png("path_to_save", width, height, channels, img, width * channels);</code></pre>
<ul>
    <li><code>width</code>: Total values in one row of the image.</li>
    <li><code>channels</code>: Number of values per pixel (3 for RGB, 4 for RGBA).</li>
    <li><code>height</code>: Number of rows in the image.</li>
</ul>

<h3>4. Looping Through Image Data</h3>
<p>The goal is to print each pixel in the image.</p>
<p><strong>How to calculate pixel index:</strong></p>
<pre><code>index = (y * width + x) * channels;</code></pre>
<ul>
    <li><code>y * width</code>: Total pixels in all rows.</li>
    <li><code>+ x</code>: Current pixel position in the row.</li>
    <li><code>* channels</code>: Find the exact byte position.</li>
</ul>

<h3>5. Summary</h3>
<ul>
    <li>Load the image.</li>
    <li>Save a copy as PNG or JPEG.</li>
    <li>Modify the image.</li>
    <li>Save the new version.</li>
</ul>



