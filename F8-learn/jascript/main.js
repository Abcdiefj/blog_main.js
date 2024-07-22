
// var boxelement=document.querySelector('.box');
// boxelement.classList.add('red')
// boxelement.classList.replace('red','rasd')
// setInterval(()=> {
// boxelement.classList.toggle('red')
// },1000)
// var a=document.querySelector('div')
// a.classList.add('sdas')b

var a=document.querySelectorAll('div')
  for(let i in a){
    a[i].onclick= function(e){
        console.log(e.target);
    }
  }
 
  var b=document.querySelector('input[type="text"]');
document.onscroll=function(){
  console.log('fdgdfgfd')
}
  b.onkeyup=function(e){  
    console.log(e.target.value)
  }
  
   var c=document.querySelector('select');
 var c=document.links;
 for(var i in c){
  c[i].onclick=(e)=>{
    if(!e.target.href.startWith('https://www.facebook.com/?locale=vi_VN')){
      e.preventDefault();
    }
  }
 }
 function viec1(){
  console.log('viec1');
 }
 function viec2(){
  console.log('viec2');
 }
 var element=document.querySelector('.abc')
element.addEventListener('click',viec1)
element.addEventListener('click',viec2)
setTimeout(function(){
element.removeEventListener('click',viec1)
},3000)
var JSOnn='{"name":"bien","age":"19"}';
console.log(JSON.parse(JSOnn))
console.log(JSON.stringify(['js','java']))


var users=[
{
  id:1,
  name:'nguyen van a'
},
{
id:2,
name:'nguyen van b'
},
{
  id:3,
  name:'nguyen van c'
}
];

var comments=[
  {
    id:1,
    id_user:1,
    comment:' 1 con vit'
  },
 {
  id:2,
  id_user:2,
  comment:'2 con thanlan con'
 }
]
function getcommnet(){
  var b;
  return new Promise(function(resolve){
    b=comments.map(function(a){
      return a.id_user;
    })
    resolve(b)
  })
}

function get_user(a){
  var b;
  return new Promise(function(resolve){
       b=users.filter(function(c){
        return a.includes(c.id);
       })
 resolve(b) })
}
getcommnet()
.then(function(a){
  return get_user(a)
})
.then(function(a){
  return {user:a,commentt:comments}
})
.then(function(data){
  var html='';
  var comment_block=document.querySelector('#box_gamming')
  data.commentt.forEach(function(element_comment){
    var c=data.user.find(function(element_user){
      return element_comment.id_user==element_user.id;
    })
    html+=`<li>${c.name} : ${element_comment.comment}<li>`;
  })
  comment_block.innerHTML=html
})

var fetchh = "https://jsonplaceholder.typicode.com/posts";
fetch(fetchh)
.then(function(response){
  return response.json();
})
.then(function(a){
  
 var html='';
 a.forEach(function(element){
  html+=`<p>${element.title}</p> `+ `<li> ${element.body}</li>`
 })
 var c=document.querySelector('#box_gamming').innerHTML=html;

})


