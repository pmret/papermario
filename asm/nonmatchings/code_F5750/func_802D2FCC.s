.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D2FCC
/* F797C 802D2FCC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* F7980 802D2FD0 AFB00010 */  sw        $s0, 0x10($sp)
/* F7984 802D2FD4 0000802D */  daddu     $s0, $zero, $zero
/* F7988 802D2FD8 AFBF0014 */  sw        $ra, 0x14($sp)
.L802D2FDC:
/* F798C 802D2FDC 3C03802E */  lui       $v1, %hi(D_802DB7C0)
/* F7990 802D2FE0 8C63B7C0 */  lw        $v1, %lo(D_802DB7C0)($v1)
/* F7994 802D2FE4 00101080 */  sll       $v0, $s0, 2
/* F7998 802D2FE8 00431021 */  addu      $v0, $v0, $v1
/* F799C 802D2FEC 8C420000 */  lw        $v0, ($v0)
/* F79A0 802D2FF0 10400006 */  beqz      $v0, .L802D300C
/* F79A4 802D2FF4 26100001 */   addiu    $s0, $s0, 1
/* F79A8 802D2FF8 8C440000 */  lw        $a0, ($v0)
/* F79AC 802D2FFC 04800003 */  bltz      $a0, .L802D300C
/* F79B0 802D3000 00000000 */   nop      
/* F79B4 802D3004 0C0483C1 */  jal       func_80120F04
/* F79B8 802D3008 00000000 */   nop      
.L802D300C:
/* F79BC 802D300C 2A020040 */  slti      $v0, $s0, 0x40
/* F79C0 802D3010 1440FFF2 */  bnez      $v0, .L802D2FDC
/* F79C4 802D3014 00000000 */   nop      
/* F79C8 802D3018 8FBF0014 */  lw        $ra, 0x14($sp)
/* F79CC 802D301C 8FB00010 */  lw        $s0, 0x10($sp)
/* F79D0 802D3020 03E00008 */  jr        $ra
/* F79D4 802D3024 27BD0018 */   addiu    $sp, $sp, 0x18
