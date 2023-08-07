// // Question 1
// function comp(a,b)
// {
//     if(a.population === b.population)
//     {
//         return (a.name<b.name);
//     }
//     return (a.population - b.population);
// }
// async function findCountry(region, keyword) {
//     let res = await axios.get(`https://jsonmock.hackerrank.com/api/countries/search?region=${region}&name=${keyword}&page=1`);
//     let n = res.data.total_pages;
//     // console.log(res.data);
//     let result = [];
//     for(let i of res.data.data)
//     {
//         result.push(i);
//     }
    
//     for(let page =2;page<=n;page++)
//     {
//         res = await axios.get(`https://jsonmock.hackerrank.com/api/countries/search?region=${region}&name=${keyword}&page=${page}`);
        
//         for(let i of res.data.data)
//         {
//             result.push(i);
//         }
//     }
    
//     // console.log(result);
//     result.sort(comp);
    
//     let ans = [];
    
//     for(let i of result)
//     {
//         ans.push(`${i.name},${i.population}`);
//     }
    
//     return ans;
// }

// // Question 2
// async function asteroidOrbits(year, orbitclass) {
//     let total = 0;
//     let response = await axios.get(`https://jsonmock.hackerrank.com/api/asteroids/search?orbit_class=${orbitclass}`);
//     let ans = []
//     // console.log(response.data);
//     total = response.data.total_pages;
//     // console.log(total);
    
//     for(let i = 1; i<=total; i++){
//         response = await axios.get(`https://jsonmock.hackerrank.com/api/asteroids/search?orbit_class=${orbitclass}&page=${i}`);
//         response = response.data.data;
//         // console.log(response);
//         for(let i = 0; i<response.length; i++){
//             let y = new Date(response[i].discovery_date).getFullYear();
//             if(y == year){
//                 let pe;
//                 if(!response[i].period_yr)
//                     pe = 1;
//                 else 
//                     pe = response[i].period_yr;
//                 ans.push({d:response[i].designation, y:y,p:pe});
//             }
//         }
//     }
//     ans.sort((a,b) => {
//                     if(a.p == b.p)
//                         return a.d.localeCompare(b.d);
//                     return a.p-b.p;
//                 }
//             )
//     //  console.log(ans.length);
//     // for(let i = 0; i<ans.length; i++){
//     //     console.log(ans[i].d, ans[i].y);
//     // }
//     let res = [];
//     for(let i = 0; i<ans.length; i++){
//         // console.log(ans[i].d);
//         res.push(ans[i].d);
//     }
//     return res;
// }

// ------------------------------------------------------------------------------------------------------
// Question 4
async function bestUniversityByCountry(country){
    let response = await axios.get(`https://jsonmock.hackerrank.com/api/universities`);
    let tot_pages = response.data.total_pages;
    let ans={uni:"",rnk:99999};
    for(let i=1;i<=tot_pages;i++){
        let resp=await axios.get(`https://jsonmock.hackerrank.com/api/transactions/search?page=${i}`);
        resp=resp.data.data;
        for(let j=0;j<resp.length;j++){
            if(country==resp[j].location.country){
                if(int(resp[j].rank_display)<ans.rnk){
                    ans.uni=resp[j].university;
                    ans.rnk=resp[j].rank_display;
                }
            }
        }
    }
    return ans.uni; 
}

// Question 3
async function maximumTransfer(name,city){
    let response = await axios.get(`https://jsonmock.hackerrank.com/api/transactions`);
    let tot_pages = response.data.total_pages;
    let maxiCred=0;
    let maxiDebt=0;
    for(let i=1;i<=tot_pages;i++){
        let resp=await axios.get(`https://jsonmock.hackerrank.com/api/transactions/search?page=${i}`);
        resp=resp.data.data;
        for(let j=0;j<resp.length;j++){
            if(city==resp[j].location.city && name==resp[j].userName){
                let amt=float(resp[j].amount.replaceAll("$","").replaceAll(",",""));
                if(resp[j].txnTyp=="credit"){
                    maxiCred=Math.max(maxiCred,amt);
                }
                else{
                    maxiDebt=Math.max(maxiDebt,amt);
                }
            }
        }
    }
    return maxiCred-maxiDebt; 
}

// Question 2
async function asteroidOrbits(year, orbitclass) {
    let response = await axios.get(`https://jsonmock.hackerrank.com/api/asteroids`);
    let tot_pages = response.data.total_pages;
    let ans = [];
    for(let i = 1; i<=tot_pages; i++){
        let resp = await axios.get(`https://jsonmock.hackerrank.com/api/asteroids/search?page=${i}`);
        resp = resp.data.data;
        for(let j = 0; j<resp.length; j++){
            if(resp[j].orbit_class==orbitclass){
                let y = new Date(resp[j].discovery_date).getFullYear();
                if(y == year){
                    let pe;
                    if(!resp[i].period_yr)
                        pe = 1;
                    else 
                        pe = resp[i].period_yr;
                    ans.push({d:response[i].designation,p:pe});
                }
            }
        }
    }
    ans.sort((a,b) => {
        if(a.p == b.p)
            return a.d.localeCompare(b.d);
        return a.p-b.p;
    });
    let res = [];
    for(let i = 0; i<ans.length; i++){
        res.push(ans[i].d);
    }
    return res;
}

// Question 1
async function findCountry(region, keyword) {
    let response = await axios.get(`https://jsonmock.hackerrank.com/api/countries`);
    // let response = await fetch(`https://jsonmock.hackerrank.com/api/countries`);
    // response = await response.json();
    let tot_pages = response.data.total_pages; 
    let ans = [];
    for(let i=1;i<=tot_pages;i++){
        let resp = await axios.get(`https://jsonmock.hackerrank.com/api/countries/search?page=${i}`);
        resp=resp.data.data;
        for(let j=0;j<resp.length;j++){
            if(resp[j].region==region && resp[j].name==keyword){
                ans.push({pop:resp[j].population,N:resp[j].name});
            }
        }
    }
    ans.sort((a,b)=>{
        if(a.pop===b.pop){
            return a.N.localeCompare(b.N);
        }
        return a.pop-b.pop;
    });
    let res=[];
    for(let i=0;i<ans.length;i++){
        res.push(`${i.N},${i.pop}`);
    }
    return res;
}