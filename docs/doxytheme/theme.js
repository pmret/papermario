// Make @evtapi prototype use Call and params
for (const item of document.querySelectorAll(".memitem:has(.evtapi)")) {
    // <a id="..." /> appears 2 children before item
    const id = item.previousElementSibling.previousElementSibling.id

    const tbody = item.querySelector(".memproto tbody")

    const name = tbody.querySelector("td.memname").childNodes[1].textContent.trim()
    const params = [`<a class="el" href="#${id}">${name}</a>`]

    for (const param of item.querySelectorAll(".params:not(.vars) .paramname")) {
        params.push(param.textContent.trim())
    }

    const proto = `Call(${params.join(", ")})`
    tbody.innerHTML = `<tr>${proto}</tr>`

    // Find its link
    const tr = document.getElementById(`r_${id}`)
    tr.innerHTML = `<td class="memItemLeft" align="right" valign="top"></td><td class="memItemRight" valign="bottom">${proto}</td>`
}

// Combine @vars tables
for (const table of document.querySelectorAll("table.vars + table.vars")) {
    const tbody = table.querySelector("tbody")
    table.previousElementSibling.querySelector("tbody").append(...tbody.childNodes)
    table.remove()
}

// Wrap @vars tables in a description
for (const table of document.querySelectorAll("table.vars")) {
    const dl = document.createElement("dl")

    const dt = document.createElement("dt")
    dt.textContent = "Variables"
    dl.appendChild(dt)

    const dd = document.createElement("dd")
    dd.innerHTML = table.outerHTML // makes copy of table
    dl.appendChild(dd)

    table.replaceWith(dl)
}

// Remove spaces in [in]/[out]/[in,out]
// These can appear because of spaces between the @vars arg separators
for (const paramdir of document.querySelectorAll("table.vars .paramdir")) {
    paramdir.textContent = paramdir.textContent.replace(/\s/g, "")
}
