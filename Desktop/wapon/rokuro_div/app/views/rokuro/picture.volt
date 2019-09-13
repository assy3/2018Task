
<script src="/js/jquery-3.4.1.min.js"></script>
<style>
img {
  -moz-user-select: none; /* Firefox */
  -ms-user-select: none; /* Internet Explorer */
  -khtml-user-select: none; /* KHTML browsers (e.g. Konqueror) */
  -webkit-user-select: none; /* Chrome, Safari, and Opera */
  -webkit-touch-callout: none; /* Disable Android and iOS callouts*/
}
.spinimage {
  position: relative;
  width: fit-content;
  width: -moz-fit-content;
  /*height: 600px;*/
  margin: auto;
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
</style>

<!-- firefoxでもプリロードするために見えないimg要素を配置する -->
<!-- <img src="0.jpg" style="opacity: 0; position: absolute">
<img src="1.jpg" style="opacity: 0; position: absolute">
<img src="2.jpg" style="opacity: 0; position: absolute"> -->

{% for rokuro in rokuros %}
  <div class="spinimage">
    {% if rokuro.id == num %}
      <div><img class="spinimage-dummy" src="{{ rokuro.imgUrls[0] }}" draggable="false" ondragstart="return false;" height="400" width="200"></div>
      <div class="spinimage-imagelist">
        <!-- 回転用画像 -->
        {% for url in rokuro.imgUrls %}
          <img src="{{ url }}" style="display: none;" draggable="false" ondragstart="return false;">
        {% endfor %}
      </div>
  {% endif %}
  </div>
{% endfor %}


<script>
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
</script>
