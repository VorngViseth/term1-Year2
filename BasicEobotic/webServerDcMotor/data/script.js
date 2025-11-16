const slider = document.getElementById("slider");
const speedText = document.getElementById("speedText");
const radios = document.getElementsByName("power");

// Update motor speed when slider moves
slider.oninput = function() {
  speedText.innerText = this.value;
  fetch("/setSpeed?value=" + this.value);
};

// Update motor direction when radio button changes
radios.forEach(radio => {
  radio.onchange = function() {
    if (this.checked) {
      fetch("/setDirection?dir=" + this.value);
    }
  };
});
