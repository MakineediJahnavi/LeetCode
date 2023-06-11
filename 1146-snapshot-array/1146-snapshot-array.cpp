class SnapshotArray {
    int snap_id;
    vector<map<int,int>> a;
public:
    SnapshotArray(int length) {
        a.resize(length);
        for (auto& history : a) {
            history[0] = 0;
        }
        snap_id=0;
    }
    
    void set(int index, int val) {
        a[index][snap_id]=val;
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto& history = a[index];
        auto it = history.upper_bound(snap_id);
        return (--it)->second;

    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */