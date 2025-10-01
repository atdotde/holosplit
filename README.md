Split files into holographic fractions

These programs split a file into parts of size roughly 1/N. Each time you invoke

<pre>holosplit <i>N filename</i></pre>

it writes a fraction file to the standard output. Each time you invoke this command you obtain a new random fraction file. With any N of the fraction files 
you can recover the original file using 

<pre>holojoin <i>N fractionfile1 ... fractionfileN</i></pre>

with high probability.

The mathematics is explained <a href=https://atdotde.blogspot.com/2025/10/holosplit.html>in this blog post<a>.
