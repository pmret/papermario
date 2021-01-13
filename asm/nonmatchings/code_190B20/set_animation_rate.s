.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_animation_rate
/* 192798 80263EB8 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19279C 80263EBC AFB00010 */  sw        $s0, 0x10($sp)
/* 1927A0 80263EC0 0080802D */  daddu     $s0, $a0, $zero
/* 1927A4 80263EC4 AFB20018 */  sw        $s2, 0x18($sp)
/* 1927A8 80263EC8 00A0902D */  daddu     $s2, $a1, $zero
/* 1927AC 80263ECC F7B40020 */  sdc1      $f20, 0x20($sp)
/* 1927B0 80263ED0 4486A000 */  mtc1      $a2, $f20
/* 1927B4 80263ED4 AFBF001C */  sw        $ra, 0x1c($sp)
/* 1927B8 80263ED8 0C09A75B */  jal       get_actor
/* 1927BC 80263EDC AFB10014 */   sw       $s1, 0x14($sp)
/* 1927C0 80263EE0 0040882D */  daddu     $s1, $v0, $zero
/* 1927C4 80263EE4 32100700 */  andi      $s0, $s0, 0x700
/* 1927C8 80263EE8 24020100 */  addiu     $v0, $zero, 0x100
/* 1927CC 80263EEC 1202000B */  beq       $s0, $v0, .L80263F1C
/* 1927D0 80263EF0 2A020101 */   slti     $v0, $s0, 0x101
/* 1927D4 80263EF4 50400005 */  beql      $v0, $zero, .L80263F0C
/* 1927D8 80263EF8 24020200 */   addiu    $v0, $zero, 0x200
/* 1927DC 80263EFC 12000010 */  beqz      $s0, .L80263F40
/* 1927E0 80263F00 0220202D */   daddu    $a0, $s1, $zero
/* 1927E4 80263F04 08098FD3 */  j         .L80263F4C
/* 1927E8 80263F08 00000000 */   nop
.L80263F0C:
/* 1927EC 80263F0C 1202000C */  beq       $s0, $v0, .L80263F40
/* 1927F0 80263F10 0220202D */   daddu    $a0, $s1, $zero
/* 1927F4 80263F14 08098FD3 */  j         .L80263F4C
/* 1927F8 80263F18 00000000 */   nop
.L80263F1C:
/* 1927FC 80263F1C 12400005 */  beqz      $s2, .L80263F34
/* 192800 80263F20 0220202D */   daddu    $a0, $s1, $zero
/* 192804 80263F24 0C099117 */  jal       get_actor_part
/* 192808 80263F28 0240282D */   daddu    $a1, $s2, $zero
/* 19280C 80263F2C 54400007 */  bnel      $v0, $zero, .L80263F4C
/* 192810 80263F30 E4540090 */   swc1     $f20, 0x90($v0)
.L80263F34:
/* 192814 80263F34 8E2201F4 */  lw        $v0, 0x1f4($s1)
/* 192818 80263F38 08098FD3 */  j         .L80263F4C
/* 19281C 80263F3C E4540090 */   swc1     $f20, 0x90($v0)
.L80263F40:
/* 192820 80263F40 0C099117 */  jal       get_actor_part
/* 192824 80263F44 0240282D */   daddu    $a1, $s2, $zero
/* 192828 80263F48 E4540090 */  swc1      $f20, 0x90($v0)
.L80263F4C:
/* 19282C 80263F4C 8FBF001C */  lw        $ra, 0x1c($sp)
/* 192830 80263F50 8FB20018 */  lw        $s2, 0x18($sp)
/* 192834 80263F54 8FB10014 */  lw        $s1, 0x14($sp)
/* 192838 80263F58 8FB00010 */  lw        $s0, 0x10($sp)
/* 19283C 80263F5C D7B40020 */  ldc1      $f20, 0x20($sp)
/* 192840 80263F60 03E00008 */  jr        $ra
/* 192844 80263F64 27BD0028 */   addiu    $sp, $sp, 0x28
