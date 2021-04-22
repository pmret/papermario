.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel clear_printers
/* B9D74 80123674 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9D78 80123678 AFB00010 */  sw        $s0, 0x10($sp)
/* B9D7C 8012367C 0000802D */  daddu     $s0, $zero, $zero
/* B9D80 80123680 AFB10014 */  sw        $s1, 0x14($sp)
/* B9D84 80123684 3C118015 */  lui       $s1, %hi(D_80154C30)
/* B9D88 80123688 26314C30 */  addiu     $s1, $s1, %lo(D_80154C30)
/* B9D8C 8012368C AFBF0018 */  sw        $ra, 0x18($sp)
.L80123690:
/* B9D90 80123690 0220202D */  daddu     $a0, $s1, $zero
/* B9D94 80123694 0000282D */  daddu     $a1, $zero, $zero
/* B9D98 80123698 0C0495A9 */  jal       initialize_printer
/* B9D9C 8012369C 00A0302D */   daddu    $a2, $a1, $zero
/* B9DA0 801236A0 26100001 */  addiu     $s0, $s0, 1
/* B9DA4 801236A4 2A020003 */  slti      $v0, $s0, 3
/* B9DA8 801236A8 1440FFF9 */  bnez      $v0, .L80123690
/* B9DAC 801236AC 26310558 */   addiu    $s1, $s1, 0x558
/* B9DB0 801236B0 24100002 */  addiu     $s0, $zero, 2
/* B9DB4 801236B4 3C028015 */  lui       $v0, %hi(D_80155C78)
/* B9DB8 801236B8 24425C78 */  addiu     $v0, $v0, %lo(D_80155C78)
/* B9DBC 801236BC 3C018015 */  lui       $at, %hi(D_801512D8)
/* B9DC0 801236C0 AC2012D8 */  sw        $zero, %lo(D_801512D8)($at)
/* B9DC4 801236C4 3C018015 */  lui       $at, %hi(D_8015130C)
/* B9DC8 801236C8 AC20130C */  sw        $zero, %lo(D_8015130C)($at)
.L801236CC:
/* B9DCC 801236CC A0400000 */  sb        $zero, ($v0)
/* B9DD0 801236D0 2610FFFF */  addiu     $s0, $s0, -1
/* B9DD4 801236D4 0601FFFD */  bgez      $s0, .L801236CC
/* B9DD8 801236D8 2442FFE0 */   addiu    $v0, $v0, -0x20
/* B9DDC 801236DC 3C018015 */  lui       $at, %hi(D_80151338)
/* B9DE0 801236E0 AC201338 */  sw        $zero, %lo(D_80151338)($at)
/* B9DE4 801236E4 3C018015 */  lui       $at, %hi(D_801512E4)
/* B9DE8 801236E8 A42012E4 */  sh        $zero, %lo(D_801512E4)($at)
/* B9DEC 801236EC 0C048DCD */  jal       load_font
/* B9DF0 801236F0 0000202D */   daddu    $a0, $zero, $zero
/* B9DF4 801236F4 8FBF0018 */  lw        $ra, 0x18($sp)
/* B9DF8 801236F8 8FB10014 */  lw        $s1, 0x14($sp)
/* B9DFC 801236FC 8FB00010 */  lw        $s0, 0x10($sp)
/* B9E00 80123700 03E00008 */  jr        $ra
/* B9E04 80123704 27BD0020 */   addiu    $sp, $sp, 0x20
