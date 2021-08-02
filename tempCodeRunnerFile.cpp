vector<vector<int> > threeSum(vector<int> &A) {
//     int sum = 0;
//     sort(A.begin(),A.end());
//     vector<vector<int> > ans;
//     for(int i=0;i<A.size();i++){
//         int left = i+1;
//         int right = A.size()-1;
//         while(left<right){
//             long long int tempAns = (long long int)A[i] + (long long int)A[left] + (long long int)A[right];
//             if(tempAns == 0){
                
//                 vector<int> temp;
//                 temp.push_back(A[i]);
//                 temp.push_back(A[left]);
//                 temp.push_back(A[right]);
//                 ans.push_back(temp);
//                 while (left < right && A[left] == temp[1]) left++;
//                 while (left < right && A[right] == temp[2]) right--;
//             }
//             else if(tempAns >(long long int)0) right--;
//             else left++;
//         }
//         while (i + 1 < A.size() && A[i + 1] == A[i]) i++;

//     }
//     return ans;
// }
