.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_80097D48
.word L800270B4_24B4, L800270E4_24E4, L8002710C_250C, L80027134_2534, L80027168_2568, 0

.section .text

glabel func_80027088
/* 2488 80027088 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 248C 8002708C 0080282D */  daddu     $a1, $a0, $zero
/* 2490 80027090 2CA20005 */  sltiu     $v0, $a1, 5
/* 2494 80027094 1040003B */  beqz      $v0, .L80027184
/* 2498 80027098 AFBF0010 */   sw       $ra, 0x10($sp)
/* 249C 8002709C 00051080 */  sll       $v0, $a1, 2
/* 24A0 800270A0 3C018009 */  lui       $at, %hi(jtbl_80097D48)
/* 24A4 800270A4 00220821 */  addu      $at, $at, $v0
/* 24A8 800270A8 8C227D48 */  lw        $v0, %lo(jtbl_80097D48)($at)
/* 24AC 800270AC 00400008 */  jr        $v0
/* 24B0 800270B0 00000000 */   nop
glabel L800270B4_24B4
/* 24B4 800270B4 24040003 */  addiu     $a0, $zero, 3
/* 24B8 800270B8 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 24BC 800270BC 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 24C0 800270C0 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 24C4 800270C4 AC25A5D8 */  sw        $a1, %lo(D_8009A5D8)($at)
/* 24C8 800270C8 8C430000 */  lw        $v1, ($v0)
/* 24CC 800270CC 2405F0FF */  addiu     $a1, $zero, -0xf01
/* 24D0 800270D0 00651824 */  and       $v1, $v1, $a1
/* 24D4 800270D4 0C0B1192 */  jal       resume_all_group
/* 24D8 800270D8 AC430000 */   sw       $v1, ($v0)
/* 24DC 800270DC 08009C61 */  j         .L80027184
/* 24E0 800270E0 00000000 */   nop
glabel L800270E4_24E4
/* 24E4 800270E4 24040001 */  addiu     $a0, $zero, 1
/* 24E8 800270E8 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 24EC 800270EC 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 24F0 800270F0 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 24F4 800270F4 AC25A5D8 */  sw        $a1, %lo(D_8009A5D8)($at)
/* 24F8 800270F8 8C430000 */  lw        $v1, ($v0)
/* 24FC 800270FC 2405F1FF */  addiu     $a1, $zero, -0xe01
/* 2500 80027100 00651824 */  and       $v1, $v1, $a1
/* 2504 80027104 08009C56 */  j         .L80027158
/* 2508 80027108 34630100 */   ori      $v1, $v1, 0x100
glabel L8002710C_250C
/* 250C 8002710C 24040002 */  addiu     $a0, $zero, 2
/* 2510 80027110 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 2514 80027114 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 2518 80027118 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 251C 8002711C AC25A5D8 */  sw        $a1, %lo(D_8009A5D8)($at)
/* 2520 80027120 8C430000 */  lw        $v1, ($v0)
/* 2524 80027124 2405F3FF */  addiu     $a1, $zero, -0xc01
/* 2528 80027128 00651824 */  and       $v1, $v1, $a1
/* 252C 8002712C 08009C56 */  j         .L80027158
/* 2530 80027130 34630300 */   ori      $v1, $v1, 0x300
glabel L80027134_2534
/* 2534 80027134 24040002 */  addiu     $a0, $zero, 2
/* 2538 80027138 3C02800A */  lui       $v0, %hi(D_8009A650)
/* 253C 8002713C 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* 2540 80027140 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 2544 80027144 AC25A5D8 */  sw        $a1, %lo(D_8009A5D8)($at)
/* 2548 80027148 8C430000 */  lw        $v1, ($v0)
/* 254C 8002714C 2405F7FF */  addiu     $a1, $zero, -0x801
/* 2550 80027150 00651824 */  and       $v1, $v1, $a1
/* 2554 80027154 34630700 */  ori       $v1, $v1, 0x700
.L80027158:
/* 2558 80027158 0C0B117A */  jal       suspend_all_group
/* 255C 8002715C AC430000 */   sw       $v1, ($v0)
/* 2560 80027160 08009C61 */  j         .L80027184
/* 2564 80027164 00000000 */   nop
glabel L80027168_2568
/* 2568 80027168 3C03800A */  lui       $v1, %hi(D_8009A650)
/* 256C 8002716C 2463A650 */  addiu     $v1, $v1, %lo(D_8009A650)
/* 2570 80027170 8C620000 */  lw        $v0, ($v1)
/* 2574 80027174 3C01800A */  lui       $at, %hi(D_8009A5D8)
/* 2578 80027178 AC25A5D8 */  sw        $a1, %lo(D_8009A5D8)($at)
/* 257C 8002717C 34420F00 */  ori       $v0, $v0, 0xf00
/* 2580 80027180 AC620000 */  sw        $v0, ($v1)
.L80027184:
/* 2584 80027184 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2588 80027188 03E00008 */  jr        $ra
/* 258C 8002718C 27BD0018 */   addiu    $sp, $sp, 0x18
