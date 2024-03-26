async function rest_request( request, data) {
    
    await fetch("/rest/" + request, { mode: "no-cors", method: "post", body: data })
}

virtual_train_form.onsubmit = async (e) => {
    e.preventDefault();
    const formData = new FormData(virtual_train_form);
    console.log(JSON.stringify (Object.fromEntries(formData)))
  
    const response = await fetch("/rest/add_virtual_trains", {
      method: "POST",
      // Set the FormData instance as the request body
      body: JSON.stringify (Object.fromEntries(formData)),
    });
  
    
  };
