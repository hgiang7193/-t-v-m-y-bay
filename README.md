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

| Mục | Chức năng | Mô tả | Cấu trúc dữ liệu & Giải thuật áp dụng |
| :---: | :--- | :--- | :--- |
| **3.1** | Quản lý chuyến bay & tra cứu vé | Lưu trữ, thêm/xóa và tra cứu nhanh theo mã chuyến bay/mã vé. | **Hash Table** |
| **3.2** | Tìm hành trình rẻ nhất | Biểu diễn mạng lưới đường bay và tìm đường đi chi phí thấp nhất. | **Graph (Danh sách kề) + Dijkstra + Min-Heap (Priority Queue)** |
| **3.3** | Đặt vé, hủy vé, danh sách chờ, hoàn tác | Quản lý khách chờ khi hết vé và hoàn tác (Undo) thao tác hủy vé. | **Queue (FIFO) + Stack (LIFO)** |
| **3.4.1** | Sắp xếp chuyến bay | Sắp xếp danh sách chuyến bay ổn định theo giá vé / giờ khởi hành. | **Merge Sort** |
| **3.4.2** | Lưu trữ dữ liệu (File I/O) | Đọc/ghi dữ liệu chuyến bay và vé, đối chiếu hiệu năng định dạng lưu trữ. | **File I/O (Text/CSV & Binary)** |

## 3. Phân công nhiệm vụ

| Thành viên | Folder đảm nhận | Nhiệm vụ chính (theo mục lục) | Các file chính dự kiến | Deadline |
| :---: | :--- | :--- | :--- | :---: |
| **Quân** | `hash_sort_quan/` | **3.1 & 3.4.1:** Cài đặt Hash Table (quản lý chuyến bay, tra cứu vé) và Merge Sort (sắp xếp chuyến bay). | `HashTable.h`, `HashTable.cpp`, `MergeSort.h`, `MergeSort.cpp` | Tuần 2 |
| **Đức** | `graph_duc/` | **3.2:** Xây dựng đồ thị (Danh sách kề), cài đặt Min-Heap / Priority Queue và thuật toán Dijkstra tìm hành trình rẻ nhất. | `Graph.h`, `Graph.cpp`, `MinHeap.h`, `Dijkstra.h`, `Dijkstra.cpp` | Tuần 2 |
| **Hoàn** | `queue_stack_hoan/` | **3.3:** Cài đặt Queue (FIFO) cho danh sách chờ và Stack (LIFO) cho hoàn tác hủy vé; xử lý đặt/hủy vé. | `Queue.h`, `Stack.h`, `BookingManager.h`, `BookingManager.cpp` | Tuần 2 |
| **Giang** | `fileio_giang/` | **3.4.2:** Xử lý đọc/ghi File I/O (Text/CSV so với Binary) và Benchmark hiệu năng. | `FileIO.h`, `FileIO.cpp`, `Benchmark.cpp` | Tuần 2 |
| **Chung** | `common/` | Các CTDL cơ bản và thực thể dùng chung (Models, Node, Array, Linked List). | `Models.h`, `Node.h`, `Array.h`, `LinkedList.h` | Tuần 1 |

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
g++ -std=c++11 main.cpp graph_duc/Graph.cpp graph_duc/Dijkstra.cpp hash_sort_quan/HashTable.cpp hash_sort_quan/MergeSort.cpp fileio_giang/FileIO.cpp queue_stack_hoan/BookingManager.cpp -o booking_system

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
