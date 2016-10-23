# eeic2017-programming-seminar

[![Build Status][travis-image]][travis-url]

[travis-url]: https://travis-ci.org/hakatashi/eeic2017-programming-seminar
[travis-image]: https://travis-ci.org/hakatashi/eeic2017-programming-seminar.svg?branch=master

EEIC2017 プログラミング基礎演習 課題参考実装

* 授業ページ: https://sites.google.com/site/hasegawalecsup/programming

そもそもシケタイじゃないし自分が提出したやつを上げてるだけなのであくまで参考で。

プルリク歓迎。

## テスト

このリポジトリには[配布資料のスライド](https://sites.google.com/site/hasegawalecsup/programming)に記載してある正しい入出力をもとに作成したテストセットと、それを実行するためのスクリプトが含まれています。これは各自が書いたプログラムが正しく書かれているかをテストするために非常に有用だと思われるので、ぜひぜひ活用してください。

### インストール

[shunit2](http://ssb.stsci.edu/testing/shunit2/shunit2.html)をカレントディレクトリにインストールする必要があります。

    curl -L "https://github.com/kward/shunit2/archive/master.tar.gz" | tar zx

### 実行

    bash test.sh
