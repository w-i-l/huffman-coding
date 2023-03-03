<h1>Huffman code</h1>
<h2>An algorithm to encode data optimally</h2>
<img src='https://user-images.githubusercontent.com/65015373/222278005-6ba91817-ec2c-4732-b96d-17492acae392.png'>
<br>
<hr>
<h2>About it</h2>

<p>The program takes as input the number of symbols, followed by them and their probabilities.<br>It displays the encoded version along with the Shanon's entropy and the current entropy.</p>
<i>It can use any ASCII symbols and any word as symbol.</i>

<br>
<hr>
<h2>How to use it</h2>

<p>All the function flow is implemented in the main function. The coding standard is to assign 0 to the left node and 1 to right, if you wish to change it, just modify the 3rd parameter of <b>encode</b> function to 1.</p>

<h3>How to run</h3>
<code bash>g++ main.c util.c -o main2</code>

<br>
<hr>
<h2>How it works</h2>

<p>All the data are read from the user from the STDIN and store in a dynamic allocated array of type <b>data</b> declared in the .h file. The data struct stores the symbols, encoded version, symbol probablity and if it's read from the user in via the original attribute.</p>

<p>After it  sorts all the symbols ascending based on their probability, it appends all the missing <b><i>"inter_symbols"</i></b> nodes.(i.e. the user choose 'A' and 'B' as symbols, the program will append "AB")</p>

<p>Having all symbols now, it sorts them descending and starts building the edges with their values(1 or 0).</p>

<b>Note that at this point the array has a structure of a heap, stored as breadth-first.</b>

