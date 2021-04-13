.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80050C80
/* 2C080 80050C80 00041100 */  sll       $v0, $a0, 4
/* 2C084 80050C84 00441023 */  subu      $v0, $v0, $a0
/* 2C088 80050C88 000210C0 */  sll       $v0, $v0, 3
/* 2C08C 80050C8C 00441021 */  addu      $v0, $v0, $a0
/* 2C090 80050C90 00021080 */  sll       $v0, $v0, 2
/* 2C094 80050C94 3C03800A */  lui       $v1, %hi(D_8009A608)
/* 2C098 80050C98 8C63A608 */  lw        $v1, %lo(D_8009A608)($v1)
/* 2C09C 80050C9C 24420024 */  addiu     $v0, $v0, 0x24
/* 2C0A0 80050CA0 00621821 */  addu      $v1, $v1, $v0
/* 2C0A4 80050CA4 8C620004 */  lw        $v0, 4($v1)
/* 2C0A8 80050CA8 10400013 */  beqz      $v0, .L80050CF8
/* 2C0AC 80050CAC 00000000 */   nop
/* 2C0B0 80050CB0 8C620008 */  lw        $v0, 8($v1)
/* 2C0B4 80050CB4 10400010 */  beqz      $v0, .L80050CF8
/* 2C0B8 80050CB8 00000000 */   nop
/* 2C0BC 80050CBC 1CC00003 */  bgtz      $a2, .L80050CCC
/* 2C0C0 80050CC0 28C20080 */   slti     $v0, $a2, 0x80
/* 2C0C4 80050CC4 08014335 */  j         .L80050CD4
/* 2C0C8 80050CC8 24060001 */   addiu    $a2, $zero, 1
.L80050CCC:
/* 2C0CC 80050CCC 50400001 */  beql      $v0, $zero, .L80050CD4
/* 2C0D0 80050CD0 2406007F */   addiu    $a2, $zero, 0x7f
.L80050CD4:
/* 2C0D4 80050CD4 10A00003 */  beqz      $a1, .L80050CE4
/* 2C0D8 80050CD8 240200FA */   addiu    $v0, $zero, 0xfa
/* 2C0DC 80050CDC 0801433A */  j         .L80050CE8
/* 2C0E0 80050CE0 A4650028 */   sh       $a1, 0x28($v1)
.L80050CE4:
/* 2C0E4 80050CE4 A4620028 */  sh        $v0, 0x28($v1)
.L80050CE8:
/* 2C0E8 80050CE8 240200FF */  addiu     $v0, $zero, 0xff
/* 2C0EC 80050CEC A062002A */  sb        $v0, 0x2a($v1)
/* 2C0F0 80050CF0 A066002B */  sb        $a2, 0x2b($v1)
/* 2C0F4 80050CF4 A0600026 */  sb        $zero, 0x26($v1)
.L80050CF8:
/* 2C0F8 80050CF8 03E00008 */  jr        $ra
/* 2C0FC 80050CFC 00000000 */   nop
