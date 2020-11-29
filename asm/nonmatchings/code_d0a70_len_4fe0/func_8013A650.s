.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8013A650
/* D0D50 8013A650 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D0D54 8013A654 AFB00010 */  sw        $s0, 0x10($sp)
/* D0D58 8013A658 3C108015 */  lui       $s0, %hi(D_80156F20)
/* D0D5C 8013A65C 26106F20 */  addiu     $s0, $s0, %lo(D_80156F20)
/* D0D60 8013A660 AFB10014 */  sw        $s1, 0x14($sp)
/* D0D64 8013A664 26110040 */  addiu     $s1, $s0, 0x40
/* D0D68 8013A668 AFBF0018 */  sw        $ra, 0x18($sp)
.L8013A66C:
/* D0D6C 8013A66C 8E020000 */  lw        $v0, ($s0)
/* D0D70 8013A670 50400015 */  beql      $v0, $zero, .L8013A6C8
/* D0D74 8013A674 26100008 */   addiu    $s0, $s0, 8
/* D0D78 8013A678 92020004 */  lbu       $v0, 4($s0)
/* D0D7C 8013A67C 2442FFFF */  addiu     $v0, $v0, -1
/* D0D80 8013A680 A2020004 */  sb        $v0, 4($s0)
/* D0D84 8013A684 304200FF */  andi      $v0, $v0, 0xff
/* D0D88 8013A688 5440000F */  bnel      $v0, $zero, .L8013A6C8
/* D0D8C 8013A68C 26100008 */   addiu    $s0, $s0, 8
/* D0D90 8013A690 92020005 */  lbu       $v0, 5($s0)
/* D0D94 8013A694 10400005 */  beqz      $v0, .L8013A6AC
/* D0D98 8013A698 00000000 */   nop      
/* D0D9C 8013A69C 0C00AB4B */  jal       heap_free
/* D0DA0 8013A6A0 8E040000 */   lw       $a0, ($s0)
/* D0DA4 8013A6A4 0804E9AF */  j         .L8013A6BC
/* D0DA8 8013A6A8 AE000000 */   sw       $zero, ($s0)
.L8013A6AC:
/* D0DAC 8013A6AC 8E040000 */  lw        $a0, ($s0)
/* D0DB0 8013A6B0 0C00AB1E */  jal       general_heap_free
/* D0DB4 8013A6B4 00000000 */   nop      
/* D0DB8 8013A6B8 AE000000 */  sw        $zero, ($s0)
.L8013A6BC:
/* D0DBC 8013A6BC A2000004 */  sb        $zero, 4($s0)
/* D0DC0 8013A6C0 A2000005 */  sb        $zero, 5($s0)
/* D0DC4 8013A6C4 26100008 */  addiu     $s0, $s0, 8
.L8013A6C8:
/* D0DC8 8013A6C8 0211102A */  slt       $v0, $s0, $s1
/* D0DCC 8013A6CC 1440FFE7 */  bnez      $v0, .L8013A66C
/* D0DD0 8013A6D0 00000000 */   nop      
/* D0DD4 8013A6D4 8FBF0018 */  lw        $ra, 0x18($sp)
/* D0DD8 8013A6D8 8FB10014 */  lw        $s1, 0x14($sp)
/* D0DDC 8013A6DC 8FB00010 */  lw        $s0, 0x10($sp)
/* D0DE0 8013A6E0 03E00008 */  jr        $ra
/* D0DE4 8013A6E4 27BD0020 */   addiu    $sp, $sp, 0x20
