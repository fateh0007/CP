 = true;
    for(int i=1;i<n;i++){
        if(a[i]<a[i-1]){
            flag = false;
            break;
        }
    }
    if(flag==false){
        cout<<-1<<endl;
        return;
    }