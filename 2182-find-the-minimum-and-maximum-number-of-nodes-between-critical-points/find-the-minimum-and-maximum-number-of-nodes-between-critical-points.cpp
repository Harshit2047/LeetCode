/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;
        int count=1;
        while(head->next->next!=NULL){
            if(head->val>head->next->val && head->next->val<head->next->next->val || head->val<head->next->val && head->next->val>head->next->next->val){
                v.push_back(count+1);
            }
            head=head->next;
            count++;
        }
        for(auto i:v){
            cout<<i<<" ";
        }
        if(v.size()==0) return{-1,-1};
        sort(v.begin(),v.end());
        int m=v[v.size()-1]-v[0];
        int mi=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            mi=min(mi,v[i+1]-v[i]);
        }
        if(m==0 || mi==INT_MAX) return {-1,-1};
        return{mi,m};
    
    }
};