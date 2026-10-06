# Cấu trúc dữ liệu & Giải thuật - Đồ án Nhóm
**Chủ đề 2:** Hệ thống đặt vé máy bay/tàu hỏa
**Thực hiện bởi:** Nhóm (4 thành viên)
**Ngôn ngữ:** C++

## 1. Yêu cầu chung
- **KHÔNG** sử dụng Standard Template Library (STL) như `std::vector`, `std::queue`, `std::stack`, `std::priority_queue`, `std::sort`, `std::map`, `std::set`.
- Chỉ sử dụng các thư viện cơ bản: `<iostream>`, `<fstream>`, `<cstring>`, `<cmath>`.
- Tự cài đặt các cấu trúc dữ liệu chính.
- Phân tích độ phức tạp (Time/Space Complexity) cho các thao tác chính trong comment code.
- Xử lý Đọc/Ghi file với dataset lớn để kiểm tra hiệu suất.

## 2. Các chức năng và Cấu trúc dữ liệu tương ứng

| Chức năng | Mô tả | Cấu trúc dữ liệu áp dụng |
| :--- | :--- | :--- |
| 1. Mạng lưới tuyến đường | Biểu diễn mạng lưới các sân bay/ga. | **Đồ thị (Graph)** |
| 2. Tìm hành trình | Tìm đường đi: ít chặng nhất (BFS), rẻ/nhanh nhất (Dijkstra), liệt kê (DFS). | **Graph traversal (BFS/DFS/Dijkstra)** |
| 3. Sơ đồ ghế | Chọn/giữ ghế trên chuyến bay/tàu. | **Mảng 2 chiều (2D Array)** |
| 4. Danh sách chờ | Quản lý người chờ khi hết vé (ưu tiên VIP). | **Queue / Priority Queue** |
| 5. Hoàn vé & Cấp ghế | Hủy vé và lấy từ danh sách chờ cấp ghế. | **Stack** (Undo) |
| 6. Tra cứu & Sắp xếp | Tra cứu vé theo mã vé, sắp xếp chuyến theo giờ/giá. | **Hash Table + Quick/Merge Sort** |

## 3. Phân công nhiệm vụ

| Thành viên | Folder đảm nhận | Nhiệm vụ chính | Các file chính | Deadline |
| :---: | :--- | :--- | :--- | :---: |
| **TV1** | `graph/` | Xây dựng đồ thị, cài đặt thuật toán BFS, DFS, Dijkstra. | `Graph.h`, `Graph.cpp`, `PathFinding.h` | Tuần 2 |
| **TV2** | `seat_sort/` | Quản lý sơ đồ ghế (mảng 2D), cài đặt thuật toán sắp xếp (Quick/Merge Sort). | `SeatMap.h`, `SeatMap.cpp`, `Sort.h` | Tuần 2 |
| **TV3** | `queue_stack/` | Cài đặt Queue, Stack cho Undo, Priority Queue cho danh sách VIP chờ. | `Queue.h`, `Stack.h`, `PriorityQueue.h`, `WaitingList.cpp` | Tuần 2 |
| **TV4** | `hashtable/` | Cài đặt Hash Table tra cứu vé, xử lý I/O đọc/ghi file dataset. | `HashTable.h`, `FileIO.h`, `FileIO.cpp` | Tuần 2 |
| **Chung** | `common/` | Các CTDL cơ bản dùng chung (Node, Array, Linked List). | `Node.h`, `Array.h`, `LinkedList.h` | Tuần 1 |

## 4. Quy ước Code (Code Convention)
- **Header Guards:** Bắt buộc sử dụng `#ifndef`, `#define`, `#endif` cho mọi file `.h`.
- **Độ phức tạp:** Phải comment rõ độ phức tạp $O()$ trên mỗi function chính.
- **Naming:** 
  - File name: `PascalCase.cpp` (VD: `SeatMap.cpp`)
  - Function/Variable name: `camelCase` (VD: `findShortestPath()`)
- **Git:** **Không** sửa code trong folder của người khác khi chưa bàn bạc. Code mỗi module cần viết sao cho có thể compile và test độc lập.

## 5. Timeline dự kiến (4 Tuần)
- **Tuần 1:** Setup repo, chốt kiến trúc, code `common/`.
- **Tuần 2:** Hoàn thiện code logic riêng ở các folder TV1-TV4.
- **Tuần 3:** Ghép code vào `main.cpp`, viết luồng chạy tổng thể.
- **Tuần 4:** Test dataset lớn, fix bug, tối ưu, viết báo cáo.

## 6. Hướng dẫn Compile & Run
**Dùng G++ (Linux/Mac) hoặc MinGW (Windows):**
```bash
# Compile
g++ -std=c++11 main.cpp graph/Graph.cpp seat_sort/SeatMap.cpp hashtable/FileIO.cpp queue_stack/WaitingList.cpp -o booking_system

# Run
./booking_system      # Linux/Mac
booking_system.exe    # Windows
```

---
**Template Header Guard mẫu:**
```cpp
#ifndef MODULE_NAME_H
#define MODULE_NAME_H

// Code của bạn ở đây

#endif // MODULE_NAME_H
```
