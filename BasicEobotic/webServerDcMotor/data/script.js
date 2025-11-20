const slider = document.getElementById("slider");
const speedText = document.getElementById("speedText");
const radios = document.getElementsByName("power");

// --- Update motor speed when slider moves ---
slider.oninput = async function() {
  speedText.innerText = this.value;
const res= await  fetch("/setSpeedAndDirection",{
    method: 'POST',
    body: JSON.stringify({value:this.value}),
    headers:{'Content-Type':'application/json'}
});
};

// --- Update motor direction when radio button changes ---
radios.forEach(radio => {
  radio.onchange = async function() {
    if (this.checked) {
      const res = await fetch('/setSpeedAndDirection',{
         method:'POST',
         body: JSON.stringify({dir:this.value}),
         headers:{'Content-Type':'application/json'}
      });
    }
  };
});
