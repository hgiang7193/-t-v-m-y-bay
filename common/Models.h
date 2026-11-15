#ifndef MODELS_H
#define MODELS_H

#include <iostream>
#include <cstring>

// ============================================================================
// 1. Bảng airports (Sân bay - Đỉnh của đồ thị)
// Khóa chính: airport_id
// ============================================================================
struct Airport {
    char airport_id[8];     // VD: "HAN", "SGN", "DAD" (Khóa chính)
    char name[64];          // Tên sân bay: "Noi Bai", "Tan Son Nhat"...
    char city[32];          // Thành phố: "Ha Noi", "TP HCM"...

    Airport() {
        airport_id[0] = '\0';
        name[0] = '\0';
        city[0] = '\0';
    }

    // Time Complexity: O(1)
    bool isValid() const {
        return airport_id[0] != '\0';
    }
};

// ============================================================================
// 2. Bảng routes (Tuyến đường bay - Cạnh của đồ thị trong Danh sách kề)
// Khóa chính: route_id
// Khóa ngoại: origin -> airports.airport_id, destination -> airports.airport_id
// Ràng buộc: base_price >= 0 (điều kiện bắt buộc để áp dụng Dijkstra),
//            cặp (origin, destination) duy nhất và origin != destination
// ============================================================================
struct Route {
    char route_id[12];      // VD: "RT001" (Khóa chính)
    char origin[8];         // Mã sân bay đi (FK -> airports)
    char destination[8];    // Mã sân bay đến (FK -> airports)
    double base_price;      // Giá vé cơ bản (Ràng buộc: >= 0 để dùng Dijkstra)
    int distance_km;        // Khoảng cách (km)

    Route() {
        route_id[0] = '\0';
        origin[0] = '\0';
        destination[0] = '\0';
        base_price = 0.0;
        distance_km = 0;
    }

    // Kiểm tra ràng buộc toàn vẹn của Route (đặc biệt điều kiện trọng số không âm cho Dijkstra)
    // Time Complexity: O(1)
    bool isValid() const {
        if (route_id[0] == '\0' || origin[0] == '\0' || destination[0] == '\0') {
            return false;
        }
        if ( std::strcmp(origin, destination) == 0 ) {
            return false;
        }
        return base_price >= 0.0;
    }
};

// ============================================================================
// 3. Bảng flights (Chuyến bay - Quản lý trong Hash Table & sắp xếp bằng Merge Sort)
// Khóa chính: flight_id
// Khóa ngoại: route_id -> routes, origin -> airports, destination -> airports
// Ràng buộc: 0 <= available_seats <= total_seats
// ============================================================================
struct Flight {
    char flight_id[12];       // VD: "VN101" (Khóa chính)
    char route_id[12];        // Mã tuyến bay (FK -> routes)
    char origin[8];           // Sân bay đi (FK -> airports)
    char destination[8];      // Sân bay đến (FK -> airports)
    char departure_time[20];  // Thời gian khởi hành chuẩn ISO: "YYYY-MM-DD HH:MM"
    double price;             // Giá vé chuyến bay (>= 0)
    int total_seats;          // Tổng số ghế
    int available_seats;      // Số ghế còn trống (0 <= available_seats <= total_seats)

    Flight() {
        flight_id[0] = '\0';
        route_id[0] = '\0';
        origin[0] = '\0';
        destination[0] = '\0';
        departure_time[0] = '\0';
        price = 0.0;
        total_seats = 0;
        available_seats = 0;
    }

    // Kiểm tra ràng buộc: 0 <= available_seats <= total_seats và price >= 0
    // Time Complexity: O(1)
    bool isValid() const {
        if (flight_id[0] == '\0' || route_id[0] == '\0') {
            return false;
        }
        if (total_seats <= 0 || available_seats < 0 || available_seats > total_seats) {
            return false;
        }
        return price >= 0.0;
    }
};

// ============================================================================
// 4. Bảng passengers (Hành khách)
// Khóa chính: passenger_id
// ============================================================================
struct Passenger {
    char passenger_id[12];  // VD: "PAX001" (Khóa chính)
    char full_name[64];     // Họ và tên hành khách
    char phone[16];         // Số điện thoại
    char id_card[20];       // Số CCCD / Passport

    Passenger() {
        passenger_id[0] = '\0';
        full_name[0] = '\0';
        phone[0] = '\0';
        id_card[0] = '\0';
    }

    // Time Complexity: O(1)
    bool isValid() const {
        return passenger_id[0] != '\0' && full_name[0] != '\0';
    }
};

// ============================================================================
// 5. Bảng bookings (Vé đặt - Tra cứu bằng Hash Table, Hoàn tác hủy bằng Stack)
// Khóa chính: booking_id
// Khóa ngoại: passenger_id -> passengers, flight_id -> flights
// Ràng buộc: status chỉ nhận "BOOKED" hoặc "CANCELLED",
//            cặp (flight_id, seat) duy nhất khi status == "BOOKED"
// ============================================================================
struct Booking {
    char booking_id[12];    // VD: "BK001" (Khóa chính)
    char passenger_id[12];  // Mã hành khách (FK -> passengers)
    char flight_id[12];     // Mã chuyến bay (FK -> flights)
    char seat[8];           // Mã ghế: VD "12A", "01B"
    char status[12];        // Trạng thái: chỉ nhận "BOOKED" hoặc "CANCELLED"
    char booking_time[20];  // Thời điểm đặt: "YYYY-MM-DD HH:MM"

    Booking() {
        booking_id[0] = '\0';
        passenger_id[0] = '\0';
        flight_id[0] = '\0';
        seat[0] = '\0';
        std::strcpy(status, "BOOKED");
        booking_time[0] = '\0';
    }

    // Kiểm tra status chỉ nhận BOOKED hoặc CANCELLED
    // Time Complexity: O(1)
    bool isValidStatus() const {
        return (std::strcmp(status, "BOOKED") == 0 ||
                std::strcmp(status, "CANCELLED") == 0);
    }

    // Time Complexity: O(1)
    bool isValid() const {
        if (booking_id[0] == '\0' || passenger_id[0] == '\0' ||
            flight_id[0] == '\0' || seat[0] == '\0') {
            return false;
        }
        return isValidStatus();
    }
};

// ============================================================================
// 6. Bảng waitlist (Danh sách chờ - Quản lý bằng Queue FIFO)
// Khóa chính kép: (flight_id, passenger_id)
// Khóa ngoại: flight_id -> flights, passenger_id -> passengers
// Ràng buộc: position duy nhất và tăng dần trong từng chuyến bay
// ============================================================================
struct WaitlistEntry {
    char flight_id[12];     // Mã chuyến bay (PK1, FK -> flights)
    char passenger_id[12];  // Mã hành khách (PK2, FK -> passengers)
    int position;           // Thứ tự chờ trong chuyến (duy nhất trong từng flight_id, >= 1)
    char request_time[20];  // Thời gian đăng ký chờ: "YYYY-MM-DD HH:MM"

    WaitlistEntry() {
        flight_id[0] = '\0';
        passenger_id[0] = '\0';
        position = 0;
        request_time[0] = '\0';
    }

    // Time Complexity: O(1)
    bool isValid() const {
        return flight_id[0] != '\0' && passenger_id[0] != '\0' && position >= 1;
    }
};

#endif // MODELS_H

