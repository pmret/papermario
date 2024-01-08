// Make @evtapi prototype use EVT_CALL and params
for (const item of document.querySelectorAll(".memitem:has(.evtapi)")) {
    // <a id="..." /> appears 2 children before item
    const id = item.previousElementSibling.previousElementSibling.id

    const tbody = item.querySelector(".memproto tbody")

    const name = tbody.querySelector("td.memname").childNodes[1].textContent.trim()
    const params = [`<a class="el" href="#${id}">${name}</a>`]

    for (const param of item.querySelectorAll(".params .paramname")) {
        params.push(param.textContent.trim())
    }

    const proto = `EVT_CALL(${params.join(", ")})`
    tbody.innerHTML = `<tr>${proto}</tr>`

    // Find its link
    const tr = document.getElementById(`r_${id}`)
    tr.innerHTML = `<td class="memItemLeft" align="right" valign="top"></td><td class="memItemRight" valign="bottom">${proto}</td>`
}
