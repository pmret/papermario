.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219F34_60A9E4
/* 60A9E4 80219F34 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 60A9E8 80219F38 AFB00010 */  sw        $s0, 0x10($sp)
/* 60A9EC 80219F3C 0080802D */  daddu     $s0, $a0, $zero
/* 60A9F0 80219F40 10A00005 */  beqz      $a1, .L80219F58
/* 60A9F4 80219F44 AFBF0014 */   sw       $ra, 0x14($sp)
/* 60A9F8 80219F48 AE000070 */  sw        $zero, 0x70($s0)
/* 60A9FC 80219F4C AE000074 */  sw        $zero, 0x74($s0)
/* 60AA00 80219F50 AE000078 */  sw        $zero, 0x78($s0)
/* 60AA04 80219F54 AE00007C */  sw        $zero, 0x7c($s0)
.L80219F58:
/* 60AA08 80219F58 8E020070 */  lw        $v0, 0x70($s0)
/* 60AA0C 80219F5C 1440000E */  bnez      $v0, .L80219F98
/* 60AA10 80219F60 00000000 */   nop      
/* 60AA14 80219F64 8E0300A8 */  lw        $v1, 0xa8($s0)
/* 60AA18 80219F68 8E020088 */  lw        $v0, 0x88($s0)
/* 60AA1C 80219F6C 00621821 */  addu      $v1, $v1, $v0
/* 60AA20 80219F70 04610004 */  bgez      $v1, .L80219F84
/* 60AA24 80219F74 AE0300A8 */   sw       $v1, 0xa8($s0)
/* 60AA28 80219F78 3C020002 */  lui       $v0, 2
/* 60AA2C 80219F7C 080867E5 */  j         .L80219F94
/* 60AA30 80219F80 00621021 */   addu     $v0, $v1, $v0
.L80219F84:
/* 60AA34 80219F84 3C040002 */  lui       $a0, 2
/* 60AA38 80219F88 0083102A */  slt       $v0, $a0, $v1
/* 60AA3C 80219F8C 10400002 */  beqz      $v0, .L80219F98
/* 60AA40 80219F90 00641023 */   subu     $v0, $v1, $a0
.L80219F94:
/* 60AA44 80219F94 AE0200A8 */  sw        $v0, 0xa8($s0)
.L80219F98:
/* 60AA48 80219F98 8E020074 */  lw        $v0, 0x74($s0)
/* 60AA4C 80219F9C 1440000E */  bnez      $v0, .L80219FD8
/* 60AA50 80219FA0 00000000 */   nop      
/* 60AA54 80219FA4 8E0300AC */  lw        $v1, 0xac($s0)
/* 60AA58 80219FA8 8E02008C */  lw        $v0, 0x8c($s0)
/* 60AA5C 80219FAC 00621821 */  addu      $v1, $v1, $v0
/* 60AA60 80219FB0 04610004 */  bgez      $v1, .L80219FC4
/* 60AA64 80219FB4 AE0300AC */   sw       $v1, 0xac($s0)
/* 60AA68 80219FB8 3C020002 */  lui       $v0, 2
/* 60AA6C 80219FBC 080867F5 */  j         .L80219FD4
/* 60AA70 80219FC0 00621021 */   addu     $v0, $v1, $v0
.L80219FC4:
/* 60AA74 80219FC4 3C040002 */  lui       $a0, 2
/* 60AA78 80219FC8 0083102A */  slt       $v0, $a0, $v1
/* 60AA7C 80219FCC 10400002 */  beqz      $v0, .L80219FD8
/* 60AA80 80219FD0 00641023 */   subu     $v0, $v1, $a0
.L80219FD4:
/* 60AA84 80219FD4 AE0200AC */  sw        $v0, 0xac($s0)
.L80219FD8:
/* 60AA88 80219FD8 8E020078 */  lw        $v0, 0x78($s0)
/* 60AA8C 80219FDC 1440000E */  bnez      $v0, .L8021A018
/* 60AA90 80219FE0 00000000 */   nop      
/* 60AA94 80219FE4 8E0300B0 */  lw        $v1, 0xb0($s0)
/* 60AA98 80219FE8 8E020090 */  lw        $v0, 0x90($s0)
/* 60AA9C 80219FEC 00621821 */  addu      $v1, $v1, $v0
/* 60AAA0 80219FF0 04610004 */  bgez      $v1, .L8021A004
/* 60AAA4 80219FF4 AE0300B0 */   sw       $v1, 0xb0($s0)
/* 60AAA8 80219FF8 3C020002 */  lui       $v0, 2
/* 60AAAC 80219FFC 08086805 */  j         .L8021A014
/* 60AAB0 8021A000 00621021 */   addu     $v0, $v1, $v0
.L8021A004:
/* 60AAB4 8021A004 3C040002 */  lui       $a0, 2
/* 60AAB8 8021A008 0083102A */  slt       $v0, $a0, $v1
/* 60AABC 8021A00C 10400002 */  beqz      $v0, .L8021A018
/* 60AAC0 8021A010 00641023 */   subu     $v0, $v1, $a0
.L8021A014:
/* 60AAC4 8021A014 AE0200B0 */  sw        $v0, 0xb0($s0)
.L8021A018:
/* 60AAC8 8021A018 8E02007C */  lw        $v0, 0x7c($s0)
/* 60AACC 8021A01C 1440000E */  bnez      $v0, .L8021A058
/* 60AAD0 8021A020 00000000 */   nop      
/* 60AAD4 8021A024 8E0300B4 */  lw        $v1, 0xb4($s0)
/* 60AAD8 8021A028 8E020094 */  lw        $v0, 0x94($s0)
/* 60AADC 8021A02C 00621821 */  addu      $v1, $v1, $v0
/* 60AAE0 8021A030 04610004 */  bgez      $v1, .L8021A044
/* 60AAE4 8021A034 AE0300B4 */   sw       $v1, 0xb4($s0)
/* 60AAE8 8021A038 3C020002 */  lui       $v0, 2
/* 60AAEC 8021A03C 08086815 */  j         .L8021A054
/* 60AAF0 8021A040 00621021 */   addu     $v0, $v1, $v0
.L8021A044:
/* 60AAF4 8021A044 3C040002 */  lui       $a0, 2
/* 60AAF8 8021A048 0083102A */  slt       $v0, $a0, $v1
/* 60AAFC 8021A04C 10400002 */  beqz      $v0, .L8021A058
/* 60AB00 8021A050 00641023 */   subu     $v0, $v1, $a0
.L8021A054:
/* 60AB04 8021A054 AE0200B4 */  sw        $v0, 0xb4($s0)
.L8021A058:
/* 60AB08 8021A058 8E040084 */  lw        $a0, 0x84($s0)
/* 60AB0C 8021A05C 0C046F07 */  jal       set_main_pan_u
/* 60AB10 8021A060 8E0500A8 */   lw       $a1, 0xa8($s0)
/* 60AB14 8021A064 8E040084 */  lw        $a0, 0x84($s0)
/* 60AB18 8021A068 0C046F0D */  jal       set_main_pan_v
/* 60AB1C 8021A06C 8E0500AC */   lw       $a1, 0xac($s0)
/* 60AB20 8021A070 8E040084 */  lw        $a0, 0x84($s0)
/* 60AB24 8021A074 0C046F13 */  jal       set_aux_pan_u
/* 60AB28 8021A078 8E0500B0 */   lw       $a1, 0xb0($s0)
/* 60AB2C 8021A07C 8E040084 */  lw        $a0, 0x84($s0)
/* 60AB30 8021A080 0C046F19 */  jal       set_aux_pan_v
/* 60AB34 8021A084 8E0500B4 */   lw       $a1, 0xb4($s0)
/* 60AB38 8021A088 8E020070 */  lw        $v0, 0x70($s0)
/* 60AB3C 8021A08C 8E030078 */  lw        $v1, 0x78($s0)
/* 60AB40 8021A090 8E040098 */  lw        $a0, 0x98($s0)
/* 60AB44 8021A094 24420001 */  addiu     $v0, $v0, 1
/* 60AB48 8021A098 AE020070 */  sw        $v0, 0x70($s0)
/* 60AB4C 8021A09C 8E020074 */  lw        $v0, 0x74($s0)
/* 60AB50 8021A0A0 24630001 */  addiu     $v1, $v1, 1
/* 60AB54 8021A0A4 AE030078 */  sw        $v1, 0x78($s0)
/* 60AB58 8021A0A8 8E030070 */  lw        $v1, 0x70($s0)
/* 60AB5C 8021A0AC 24420001 */  addiu     $v0, $v0, 1
/* 60AB60 8021A0B0 AE020074 */  sw        $v0, 0x74($s0)
/* 60AB64 8021A0B4 8E02007C */  lw        $v0, 0x7c($s0)
/* 60AB68 8021A0B8 0064182A */  slt       $v1, $v1, $a0
/* 60AB6C 8021A0BC 24420001 */  addiu     $v0, $v0, 1
/* 60AB70 8021A0C0 14600002 */  bnez      $v1, .L8021A0CC
/* 60AB74 8021A0C4 AE02007C */   sw       $v0, 0x7c($s0)
/* 60AB78 8021A0C8 AE000070 */  sw        $zero, 0x70($s0)
.L8021A0CC:
/* 60AB7C 8021A0CC 8E020074 */  lw        $v0, 0x74($s0)
/* 60AB80 8021A0D0 8E03009C */  lw        $v1, 0x9c($s0)
/* 60AB84 8021A0D4 0043102A */  slt       $v0, $v0, $v1
/* 60AB88 8021A0D8 50400001 */  beql      $v0, $zero, .L8021A0E0
/* 60AB8C 8021A0DC AE000074 */   sw       $zero, 0x74($s0)
.L8021A0E0:
/* 60AB90 8021A0E0 8E020078 */  lw        $v0, 0x78($s0)
/* 60AB94 8021A0E4 8E0300A0 */  lw        $v1, 0xa0($s0)
/* 60AB98 8021A0E8 0043102A */  slt       $v0, $v0, $v1
/* 60AB9C 8021A0EC 50400001 */  beql      $v0, $zero, .L8021A0F4
/* 60ABA0 8021A0F0 AE000078 */   sw       $zero, 0x78($s0)
.L8021A0F4:
/* 60ABA4 8021A0F4 8E02007C */  lw        $v0, 0x7c($s0)
/* 60ABA8 8021A0F8 8E0300A4 */  lw        $v1, 0xa4($s0)
/* 60ABAC 8021A0FC 0043102A */  slt       $v0, $v0, $v1
/* 60ABB0 8021A100 50400001 */  beql      $v0, $zero, .L8021A108
/* 60ABB4 8021A104 AE00007C */   sw       $zero, 0x7c($s0)
.L8021A108:
/* 60ABB8 8021A108 8FBF0014 */  lw        $ra, 0x14($sp)
/* 60ABBC 8021A10C 8FB00010 */  lw        $s0, 0x10($sp)
/* 60ABC0 8021A110 0000102D */  daddu     $v0, $zero, $zero
/* 60ABC4 8021A114 03E00008 */  jr        $ra
/* 60ABC8 8021A118 27BD0018 */   addiu    $sp, $sp, 0x18
/* 60ABCC 8021A11C 00000000 */  nop       
