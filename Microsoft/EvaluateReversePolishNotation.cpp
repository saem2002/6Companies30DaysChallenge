class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        stack<long> st;
        long ans =0;
        for(int i=0;i<tokens.size();i++)
        {
            // if(!st.empty())
            // {
            //     cout<<st.top()<<" ";
            // }
           
            if(tokens[i]=="+" || tokens[i]=="-"  || tokens[i]=="*" || tokens[i]=="/")
            {
                int a,b;
                if(!st.empty())
                {
                    a = st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    b = st.top();
                    st.pop();
                }
                if(tokens[i]=="*")
                {
                    long store = a*b;
                    st.push(store);
                }
                if(tokens[i]=="+")
                {
                    long store = a+b;
                    st.push(store);
                }
                if(tokens[i]=="-")
                {
                    long store = b-a;
                    st.push(store);
                }
                if(tokens[i]=="/")
                {
                    long store = b/a;
                    if(a!=0)st.push(store);
                }
            }else{
                cout<<tokens[i]<<" ";
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};