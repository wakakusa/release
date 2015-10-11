kuikjulia
===

##このアプリケーションは？
juliaのスクリプト記述と実行を補助するアプリケーションです。

##必要なライブラリ
<tr><td>cmake >= 2.64</td></tr>
<tr><td>GTk+3 >= 3.14</td></tr>
<tr><td>gtksourceview >= 3.14</td></tr>
<tr><td>vte >= 0.38</td></tr>
<tr><td>gmodule >= 2.42</td></tr>

gtksourceviewとvteはgladeでも利用できるようにオプションを有効にしておく。

##コンパイル方法
<tr><td>以下の手順で実行してください。ダウンロードしてきたファイル名をkuikujulia-*.tar.gzとします。</td></tr>
<tr><td>tar zxf kuikjulia-*.tar.gz</td></tr>
<tr><td>cd kuikjulia-*</td></tr>
<tr><td>cmake .</td></tr>
<tr><td>make</td></tr>

##実行方法
解凍した圧縮ファイルのディレクトリ配下で以下のコマンドを実行してください。
./src/kuikjulia

##ショートカットキー
<table>
<tr><td>command</td>	<td>shortcut kye</td></tr>
<tr><td>copy	</td>	<td>Ctrl+c</td></tr>
<tr><td>paste</td>		<td>Ctrt+v</td></tr>
<tr><td>undo	</td>	<td>Ctrl+z</td></tr>
<tr><td>redo	</td>	<td>Ctrl+y</td></tr>
</table>