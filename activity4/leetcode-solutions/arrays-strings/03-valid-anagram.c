bool isAnagram(char* s, char* t) 
{
    int i=0;
    if(strlen(s)!=strlen(t))
    {
        return false;
    }
    int count[26]={0};

    for(i=0;s[i]!='\0';i++)
    {
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }

    for(i=0;i<26;i++)
    {
        if(count[i]!=0)
        {
            return false;
        }
    }
    return true;
}