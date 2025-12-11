// function challenge1(width, height) {
//     let rectangleString = '';
//     // Your code
//    for(let i = 0; i < height; i++) {
//        for(let j=0; j < width; j++) {
//            rectangleString  += '* ';
//        }
//        rectangleString += '\n';
//    }
//     return rectangleString;
// }


// console.log(challenge1(3,-2));

// function challenge2(arr) {
//     arr.reverse();
//     return arr;
// }

// console.log(challenge2([1,2,3,4]));

// function challenge3(arr) {
//     const subjects = arr.length;
//     let sum = 0;

//     for(let i=0;  i < subjects; i++) {
//         sum += arr[i];
//     }

//     return sum / subjects;
// }

// console.log(challenge3([10,20,30]));

// function  challenge4(string, char) {
//     let res = 0;
//     for(let i = 0; i < string.length; i++) {
//         if(string[i] == char) res++;
//     }

//     return res;
// }

// console.log(challenge4("aaa s aaa", "s"));

// function challenge5(string) {
//     let res = 0
//     for(let i =0; i < string.length; i++) {
//         while(string[i] == " ") i++;
//         res++ ;
//         while(i < string.length && string[i] !== " ") i++;
//     }
    
//     return res;
// }

// console.log(challenge5("tv na   sdsfsdf     ot te"));

// function challenge6(votes) {
//     let voteCount = [];
//     for(const vote of votes) {
//         voteCount[vote] = (voteCount[vote] || 0) +1;
//     }

//     let max = 0;
//     for(const candidate in voteCount) {
//         if(voteCount[candidate] > max) max=voteCount[candidate];
//     }

//     let winner = [];
//     for(const candidate in voteCount) {
//         if(voteCount[candidate] == max) {
//             winner.push(candidate);
//         }
//     }

//     return winner;
// }   

// console.log(challenge6(['a','a','b','b']))  