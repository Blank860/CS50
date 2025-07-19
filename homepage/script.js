function showAlert() {
    const email = document.getElementById("email").value;
    const thanks = document.getElementById("thanks");
    thanks.innerHTML = `Thanks for subscribing, ${email}!`;
    thanks.classList.add("alert", "alert-success");
}
