
var noQuizzDivHidding = false;

var _quizz_nreplies=0;
var _quizzes;


function parseCheckbox(quizz, question, bElem) {
  var b = new Object();
  b.question = question;
  b.no = question.checkboxes.length;
  question.checkboxes[question.checkboxes.length] = b;
  b.type = "checkbox";
  b.label = bElem.innerHTML;
}

function parseCheckboxes(quizz, question, bElems) {
  var child = bElems.firstChild;
  while (child) {
    if (child.localName == "checkbox") 
      parseCheckbox(quizz, question, child);
    child = child.nextSibling;
  }
}

function parseAnswer(quizz, question, bElem) {
  var b = new Object();
  b.question = question;
  b.no = question.answers.length;
  question.answers[question.answers.length] = b;
  b.innerHTML = bElem.innerHTML;
  b.checks = bElem.getAttribute("checks");
}

function parseAnswers(quizz, question, bElems) {
  var child = bElems.firstChild;
  while (child) {
    if (child.localName == "answer") 
      parseAnswer(quizz, question, child);
    child = child.nextSibling;
  }
}


function parseHint(quizz, question, bElem) {
  var b = new Object();
  b.question = question;
  b.no = question.hints.length;
  question.hints[question.hints.length] = b;
  b.innerHTML = bElem.innerHTML;
  b.checks = bElem.getAttribute("checks");
}

function parseHints(quizz, question, bElems) {
  var child = bElems.firstChild;
  while (child) {
    if (child.localName == "hint") 
      parseHint(quizz, question, child);
    child = child.nextSibling;
  }
}

function parseQuestion(quizz, qElem) {
  var question = new Object();
  question.quizz = quizz;
  question.validated = false;
  question.no = quizz.questions.length;
  quizz.questions[quizz.questions.length] = question;
  var style = qElem.getAttribute("style");
  style = "display: none; "+style;
  qElem.setAttribute("style",style);
  var child = qElem.firstChild;
  while (child) {
    if (child.localName == "p" || child.localName == "div" ) {
      question.text = child.innerHTML;
      break;
    }
    child = child.nextSibling;
  }
  child = qElem.firstChild;
  question.checkboxes = new Array();
  question.hints = new Array();
  question.answers = new Array();

  while (child) {
    if (child.localName == "answers") {
      parseAnswers(quizz, question, child);
    } else if (child.localName == "hints") {
      parseHints(quizz, question, child);
    } else if (child.localName == "checkboxes") {
      parseCheckboxes(quizz, question, child);
    } else if (child.localName == "finally") {
      question.finally = child.innerHTML;
    }
    child = child.nextSibling;
  }
}

function parseQuizzes() {
  var q = 0;
  var zno = q+1;
  var d = document.getElementById("id_quizz"+zno);
  while (d) {
    var quizz = new Object();
    _quizzes[q] = quizz;
    quizz.no = q;
    quizz.zno = zno;
    quizz.d = d;
    quizz.ntries = 4;
    quizz.name = d.getAttribute("name");
    quizz.numbers = d.getAttribute("enumerate")=='yes';
    quizz.bullets = d.getAttribute("itemize")=='yes';
    quizz.questions = new Array();
    var child = d.firstChild;
    while (child) {
      if (child.localName == "question") 
	parseQuestion(quizz, child);
      child = child.nextSibling;
    }
    q++;
    zno++;
    d = document.getElementById("id_quizz"+zno);
  }
  genQuizzes();
}

/*
 * id_qlz : Query Label quizZ
 * id_qbz : Query Button quizZ
 * 
 */
function genCheckbox(b) {
  var q = b.question;
  var lid = 'id_qlz'+q.quizz.zno+'q'+q.no+'b'+b.no;
  var id = 'id_qbz'+q.quizz.zno+'q'+q.no+'b'+b.no;
  var innerHTML;
  innerHTML = '<input type="checkbox" id="'+id+'" value="'+b.click+'">';
  innerHTML += '<label id="'+lid+'" for="'+id+'">'+b.label+'</label>'
  return innerHTML;
}

/*
 * id_qrz: Query Response QuizZ
 */
function genQuestion(q) {
  var innerHTML = '<p>'+q.text+'</p>';
  var len = q.checkboxes.length;
  for (i=0;i<len;i++) {
    innerHTML += genCheckbox(q.checkboxes[i],innerHTML);
    innerHTML+='<br>';
  }
  var id = 'id_qrz'+q.quizz.zno+'q'+q.no;
  innerHTML += '<p id="'+id+'" style="display: none"></p>';

  return innerHTML;
}

function genQuizz(quizz) {
  var innerHTML;
  var d = quizz.d;
  if (quizz.validated) {
    d.style.display = 'none';
    quizzShowNext(quizz);
    return;
  }
  innerHTML="<p><b>Quizz:</b> "+quizz.no+"</p>";
  if (quizz.bullets) 
    innerHTML+="<ul>";
  else if (quizz.numbers)
    innerHTML+="<ol>";

  var len = quizz.questions.length;
  for (q=0;q<len;q++) {
    var question = quizz.questions[q];
    if (quizz.bullets || quizz.numbers)
      innerHTML += "<li>";
    innerHTML += genQuestion(question,innerHTML);
    if (quizz.bullets || quizz.numbers)
      innerHTML += "</li>";
  }
  if (quizz.bullets) 
    innerHTML+="</ul>";
  else if (quizz.numbers)
    innerHTML+="</ol>";

  var id = 'id_qdz'+quizz.zno;
  innerHTML += '<br><button id="'+id+'" type="button" onclick="quizzDone(this)">';
  innerHTML += 'Submit';
  innerHTML += '</button>';
  
  d.innerHTML = innerHTML;
  d.style.display = 'block';

  var nid = "id_quizz"+quizz.zno+"_next";
  var n = document.getElementById(nid);
  if (n) {
    if (noQuizzDivHidding)
      n.style.display = 'block';
    else
      n.style.display = 'none';      
  }
  return;
}

function genQuizzes() {
  var i;
  var len = _quizzes.length;
  for (i=0;i<len;i++) {
    var quizz = _quizzes[i];
    genQuizz(quizz);
  }
}

function quizzValidatedCheckboxQuestion(quizz, question) {
  question.validated = false;
  var checkedStatus= "";
  for (k=0; k<question.checkboxes.length;k++) {
    var checkbox = question.checkboxes[k];
    var pid = "id_qbz"+quizz.zno+"q"+question.no+'b'+checkbox.no;
    var p = document.getElementById(pid);
    if (p==null)
      return;
    if (p.checked) 
      checkedStatus+='C';
    else
      checkedStatus+='U';
  }
  var answers = question.answers;
  for (a=0;a<answers.length;a++) {
    var checks = answers[a].checks;
    if (checks==checkedStatus) {
      question.answer = answers[a];
      question.validated = true;
      return true;
    }
    var match=true;
    for (i=0;match && i<checks.length;i++) {
      var c1 = checks.charAt(i);
      var c2 = checkedStatus.charAt(i);
      if (c1!=c2 && c1!='?') 
	match = false;
    }
    if (match) {
      question.answer = answers[a];
      question.validated = true;
      return true;
    }
  }
  return false;
}

function quizzValidated(quizz) {
  if (quizz.validated)
    return;
  quizz.validated = true;
  for (j=0;j<quizz.questions.length;j++) {
    var q = quizz.questions[j];
    q.validated = true;
    if (q.buttons) {
      for (k=0;q.validated && k<q.buttons.length;k++) {
	var b = q.buttons[k];
	if (!b.neither) {
	  if (b.click)
	    q.validated &= b.clicked;
	  else
	    q.validated &= !b.clicked;
	}
      }
    } else if (q.checkboxes) {
      quizzValidatedCheckboxQuestion(quizz, q);
    }
    quizz.validated &= q.validated;
  }
  /*
  if (quizz.name) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
      }
    };
    var name = sprint.name+":"+task.name+":"+quizz.name
    var url;
    if (quizz.validated)
      url = "/passedQuizz?"+name;
    else
      url = "/failedQuizz?"+name;
    xhttp.open("GET", url, true);
    xhttp.send();
  }
  */
}

function quizzSelectHints(quizz, question) {
  var result = new Array();
  if (question.hints) {
    var checkedStatus= "";
    for (k=0; k<question.checkboxes.length;k++) {
      var checkbox = question.checkboxes[k];
      var pid = "id_qbz"+quizz.zno+"q"+question.no+'b'+checkbox.no;
      var p = document.getElementById(pid);
      if (p==null)
	return;
      if (p.checked) 
	checkedStatus+='C';
      else
	checkedStatus+='U';
    }
    var hints = question.hints;
    for (h=0;h<hints.length;h++) {
      var checks = hints[h].checks;
      if (checks==checkedStatus) 
	result[result.length] = hints[h];
      else {
	var match=true;
	for (i=0;match && i<checks.length;i++) {
	  var c1 = checks.charAt(i);
	  var c2 = checkedStatus.charAt(i);
	  if (c1!=c2 && c1!='?') 
	    match = false;
	}
	if (match)
	  result[result.length] = hints[h];
      }
    }
  }
  return result;
}


function quizzShowNext(quizz) {
  var next = "id_quizz"+quizz.zno+"_next";
  var d = document.getElementById(next);
  if (d) {
    d.style.display = 'block';
    if (!isElementInViewport(d)) {
      var p = null;
      var child = d.firstChild;
      while (child) {
	if (child.localName == "p") {
	  p = child;
	  break;
	}
	child = child.nextSibling;
      }
      if (p)
	p.scrollIntoView(false); // scroll the div at the top
      else
	d.scrollIntoView(false); // scroll the div at the top
    }
  }
}

function quizzDone(bElem) {
  var id = bElem.id;
  // id = id_qdz1
  var parts = id.split('z');  
  var zno = parts[1];
  for (i=0;i<_quizzes.length;i++) {
    var quizz = _quizzes[i];
    if (quizz.zno==zno) {
      if (quizz.validated)
	return;
      quizzValidated(quizz);
      quizz.ntries--;
      var pid = 'id_qdz'+quizz.zno;
      var p = document.getElementById(pid);
      if (p) {
	for (j=0;j<quizz.questions.length;j++) {
	  var q = quizz.questions[j];
	  var rid = 'id_qrz'+quizz.zno+'q'+q.no;
	  var r = document.getElementById(rid);
	  if (r) 
	    r.style.display = 'none';
	}
	if (quizz.validated) {
	  quizzShowNext(quizz);
	  p.style.display = 'none';
	  // p.style.color = "blue";
	  // p.innerHTML="Done";
	  for (j=0;j<quizz.questions.length;j++) {
	    var q = quizz.questions[j];
	    if (q.answer) {
	      var rid = 'id_qrz'+quizz.zno+'q'+q.no;
	      var r = document.getElementById(rid);
	      if (r) {
		r.style.display = 'block';
		r.style.color = "blue";
		r.innerHTML = q.answer.innerHTML;
	      }
	    }
	  }
	} else if (quizz.ntries<=0) {
	  quizzShowNext(quizz);
	  p.style.color = "blue";
	  p.innerHTML="Giving up.";
	  for (j=0;j<quizz.questions.length;j++) {
	    var q = quizz.questions[j];
	    var rid = 'id_qrz'+quizz.zno+'q'+q.no;
	    var r = document.getElementById(rid);
	    if (r && q.finally) {
	      r.style.display = "block";
	      r.style.color = "blue";
	      r.innerHTML = q.finally;
	    }
	  }	  

	} else {
	  p.style.color = "red";
	  p.innerHTML="Retry ("+quizz.ntries+")";
	  for (j=0;j<quizz.questions.length;j++) {
	    var q = quizz.questions[j];
	    var rid = 'id_qrz'+quizz.zno+'q'+q.no;
	    var r = document.getElementById(rid);
	    if (r) {
	      var hints = quizzSelectHints(quizz,q);
	      if (hints && hints.length!=0) {
		r.style.display = "block";
		r.style.color = "green";
		var innerHTML = "";
		for (h=0;h<hints.length;h++) {
		  innerHTML += '<p>'+hints[h].innerHTML+'</p>';
		}
		r.innerHTML = innerHTML;
	      }
	    }
	  }	  
	}
      }
      return;
    }
  }
}

function quizzClick(bElem) {
  var id = bElem.id;
  // id = id_qbz1q2b1
  var parts = id.split('z');  
  parts = parts[1].split('q');
  var zno = parts[0];
  parts = parts[1].split('b');
  var qno = parts[0];
  var bno = parts[1];

  for (i=0;i<_quizzes.length;i++) {
    var quizz = _quizzes[i];
    if (quizz.zno==zno) {
      if (quizz.validated)
	return;
      for (j=0;j<quizz.questions.length;j++) {
	var q = quizz.questions[j];
	if (q.no==qno && !q.validated) {
	  for (k=0;k<q.buttons.length;k++) {
	    var b = q.buttons[k];
	    var pid = "id_qrz"+zno+"q"+qno+'b'+b.no;
	    var p = document.getElementById(pid);
	    if (p) {
	      if (b.no==bno) {
		p.style.display = 'block'; // 'inline';
		b.clicked = true;
	      } else {
		if (!b.click) {
		  b.clicked = false;
		  p.style.display = 'none';
		}
	      }
	    }
	  }
	  quizzValidated(quizz);
	  return;
	}
      }
    }
  }
}

