<script src="/js/jquery-3.4.1.min.js"></script>
<script src="./js/bootstrap.js"></script>
<link rel="stylesheet" href="./css/bootstrap.css">
<!-- Semantic UI を読み込む -->
<link rel="stylesheet" href="https://cdn.jsdelivr.net/semantic-ui/2.2.10/semantic.min.css">
<!-- fontawesome を読み込む -->
<link href="https://use.fontawesome.com/releases/v5.6.1/css/all.css" rel="stylesheet">

<style>
img {
  -moz-user-select: none; /* Firefox */
  -ms-user-select: none; /* Internet Explorer */
  -khtml-user-select: none; /* KHTML browsers (e.g. Konqueror) */
  -webkit-user-select: none; /* Chrome, Safari, and Opera */
  -webkit-touch-callout: none; /* Disable Android and iOS callouts*/
}

.backButton{
  margin-top: 20px;
  margin-right: 25px;
}

.deleteButton{
  text-align: center;
  margin-top: 25px;
  margin-left: 120px;
	margin-bottom: 5px;
}

.spinimage {
  position: relative;
  width: fit-content;
  width: -moz-fit-content;
  /*height: 600px;*/
  margin: auto;
  margin-bottom: 50px;
  /* background-color: pink; */
}
.spinimage-imagelist img {
  position: absolute;
  top: 0;
  left: 0;
  height: 100%;
}
img.spinimage-dummy {
  height: 100%;
}

.title{
  /* border: 1px solid #aaa; */
  /* width: 400px; */
  font-size: 50px;
  text-align: center;
}

.description{
  text-align: center;
  max-width: 50%;
  background-color: #eee8aa;
  margin: 0 auto;
  /* display:flex
  align-self: center; */
}

.explain{
  /* margin-bottom: 40px; */
  text-decoration: underline;
  color:red;
}

.item{
  margin-top: 20px;
}

</style>

{{partial('navbar')}}

<!-- firefoxでもプリロードするために見えないimg要素を配置する -->
<!-- <img src="0.jpg" style="opacity: 0; position: absolute">
<img src="1.jpg" style="opacity: 0; position: absolute">
<img src="2.jpg" style="opacity: 0; position: absolute"> -->

<!-- 戻るボタン -->
<!-- <button type="button" class="backButton" name="name" onclick="location.href='/rokuro'">戻る</button> -->
<i class="fa fa-history backButton" style="font-size:20px"><a href="/rokuro" class="card-link">戻る</a></i>

<!-- <h1>詳細画面</h1> -->
<div class="title">タイトル</div>
<!--以下のコメント文は後で使う可能性があるため消さないこと。-->
<!--<input type = "image" src="images/.png" alt="編集画面">
		<input type = "image" src="images/.png" alt="削除画面">-->

<!-- 回転画像表示 -->
{% for rokuro in rokuros %}
    {% if rokuro.id == num %}
    <!-- <div>No,{{ rokuro.id }}</div> -->

    <div class="deleteButton">
        {# <i class="fa fa-edit" style="font-size:20px"><a href="/rokuro/delete/{{ rokuro.id }}" class="card-link">編集</a></i>
        <i class="fa fa-trash" aria-hidden="true" style="font-size:20px"><button onclick="msgdsp()">削除</button></i> #}
				<button onclick="edit_text()"><i class="fa fa-edit" style="font-size:20px"></i></button>
				<button onclick="delete_picture()"><i class="fa fa-trash" aria-hidden="true" style="font-size:20px"></i></button>
        <!-- <i class="fa fa-edit" style="font-size:20px"><a href="/rokuro/delete/{{ rokuro.id }}" class="card-link">編集</a></i>
        <i class="fa fa-trash" aria-hidden="true" style="font-size:20px"><a href="/rokuro/delete/{{ rokuro.id }}" class="card-link">削除</a></i> -->

        {# <p><input type="button" name="B1" value="このボタンを押すとアラートを表示します" onclick="msgdsp()"></p> #}
        {# <button onclick="msgdsp()">コピー</button> #}
    </div>
    <div class="spinimage">

      <div><img class="spinimage-dummy" src="{{ rokuro.imgUrls[0] }}" draggable="false" ondragstart="return false;" height="400" width="200"></div>
      <div class="spinimage-imagelist">
        <!-- 回転用画像 -->
        {% for url in rokuro.imgUrls %}
            <img src="{{ url }}" style="display: none;" draggable="false" ondragstart="return false;">
            <!-- <img class="spinimage-dummy" src="/image/{{ rokuro.id }}/{{ rokuro.id2 }}" draggable="false" ondragstart="return false;" height="250" width="150"> -->
        {% endfor %}
      </div>
  {% endif %}
  </div>
{% endfor %}


<div class="description">
  <!-- 画像説明文 -->

  <div class="explain" style="padding: 10px; margin-bottom: 10px; max-width:50%  border: 1px dashed #333333; border-radius: 5px; background-color: #ffff99;">
    説明文
    ここに文字を入力する。
    あああああいいいいいいいいいいいいいいいいいいいいいいい
    いいいいいいいいいいいいいいいいおおおおおおおおおおおお
    おおおおおいいい
    ここここここ
  </div>

  <div class="item">No,{{ num }}</div>
  <!-- 投稿日時/回転数 -->
  <div class="item">{{ rokuro.count }}回転</div>
  <div class="item">投稿日時{{ create_data }}</div>

  <!-- 共有 -->
    <div style="margin: 5px">
      <!--twitterページ-->
      <a href="https://twitter.com/share?url=http://192.168.33.10/rokuro/spin/{{rokuro.id}}&text=あなたのろくろを共有" rel="nofollow" target="_blank"><img src="/img/twitter.png" alt="twitter共有" height="34" width="34"></a>
      <!--Facebookページ 追記:現在のアドレスは共有できないらしいため、いったん放置しておきます-->
      <a href="http://www.facebook.com/share.php?u=http://192.168.33.10/rokuro/spin/{{rokuro.id}}" rel="nofollow" target="_blank"><img src="/img/facebook.png" alt="Facebook共有" height="34" width="34"></a>
      <!--はてなページ-->
      <a href="http://b.hatena.ne.jp/add?mode=confirm&url=http://192.168.33.10/rokuro/spin/{{rokuro.id}}&title=ろくろページ" target="_blank" rel="nofollow"><img src="/img/hatena.png" alt="はてなブックマーク共有" height="34" width="34"></a>
      <!--LINEページ-->
      <a href="http://line.me/R/msg/text/?http://192.168.33.10/rokuro/spin/{{rokuro.id}}" target="_blank" rel="nofollow"><img src="/img/line.png" alt="LINE共有" height="34" width="34"></a>
    </div>

  <div class="item"><input id="copyURL" type="text" size="40" maxlength="20" value="http://192.168.33.10/rokuro/spin/picture/{{rokuro.id}}"></div>
  <button onclick="clickCopyBtnURL()">コピー</button>

  <div class="item"><textarea id="copyIframe" value="1" cols="50" rows=5 maxlength="15"><iframe src="http://192.168.33.10/rokuro/spin/picture/{{rokuro.id}}" width="250" height="400"></iframe></textarea></div>
  <button onclick="clickCopyBtnIframe()">コピー</button>

</div>


<script>

function clickCopyBtnURL(){
  /* コピー対象をJavaScript上で変数として定義する*/
  var copyCode = document.getElementById("copyURL");
  /* コピー対象のテキストを選択する*/
  copyCode.select();
  /* 選択しているテキストをクリップボードにコピーする*/
  document.execCommand("Copy");
}

function clickCopyBtnIframe(){
  /* コピー対象をJavaScript上で変数として定義する*/
  var copyCode = document.getElementById("copyIframe");
  /* コピー対象のテキストを選択する*/
  copyCode.select();
  /* 選択しているテキストをクリップボードにコピーする*/
  document.execCommand("Copy");
}

$('.spinimage').each(function() {
  var isSpinning = false;
  var index = 1;
  var $imgs = $('.spinimage-imagelist img');
  var imageCount = $imgs.length;
  var mouseStartX = 0;
  var startIndex = 0;
  var $previousImg = $imgs.eq(0);
  var speed = 0;
  var interval;
  var preX = 0;

  $('.spinimage').on('mousedown', function(e) {
    if (e.which == 1) {
      isSpinning = true;
      mouseStartX = e.screenX;
      preX = e.screenX;
      speed = 0;
    } else {
      finishSpinning();
    }
  });
  $(window).on('mousemove', function(e) {
    if (isSpinning) {
      /* まわす */
      var relativeIndex = parseInt((e.screenX - mouseStartX) / 10);

      index = (startIndex + relativeIndex) % imageCount;
      showImageOf(index);
      speed = e.screenX - preX;
      preX = e.screenX;
      console.log(speed);
    }
  }).on('mouseup', function(e) {
    finishSpinning();
  });

  function finishSpinning() {
    startIndex = index;
    isSpinning = false;

    var indexAsFloat = parseFloat(index);
    clearInterval(interval);
    interval = setInterval(function() {
      indexAsFloat = (indexAsFloat + speed) % imageCount;
      startIndex = parseInt(indexAsFloat);
      showImageOf(startIndex);
      index = startIndex;

      speed = speed * 0.995;
      if (speed > 0) {
        speed = speed - speed * speed * 0.001;
      } else {
        speed = speed + speed * speed * 0.001;
      }
      if (Math.abs(speed) < 0.1) {
        clearInterval(interval);
      }
    }, 30);
  }

  function showImageOf(index) {
    var $newImg = $imgs.eq(index);
    if (!$newImg.is($previousImg)) {
      $newImg.show(0, function() {
        $previousImg.hide();
        $previousImg = $newImg;
      });
    }
  }
});

  function delete_picture() {
    var t_f = window.confirm("本当に削除しますか？");
    if (t_f) {
      location.href = "/rokuro/delete/{{ rokuro.id }}";
    }

  }

	function edit_text() {
    var t_f = window.confirm("編集しますか？");
    if (t_f) {
      location.href = "/rokuro/delete/{{ rokuro.id }}";
    }
	}

</script>
