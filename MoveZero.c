void moveZeroes(int* nums, int numsSize) {
    int index=0;
    for(int i=0;i<numsSize;i++){
        if(nums[i]!=0){
            nums[index]=nums[i];
            index++;
        }
    }
    for(int i=index;i<numsSize;i++){
        nums[index]=0;
        index++;
    }
    
}