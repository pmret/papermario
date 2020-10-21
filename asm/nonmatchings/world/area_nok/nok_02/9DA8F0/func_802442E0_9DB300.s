.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802442E0_9DB300
/* 9DB300 802442E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DB304 802442E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DB308 802442E8 0080802D */  daddu     $s0, $a0, $zero
/* 9DB30C 802442EC AFBF0014 */  sw        $ra, 0x14($sp)
/* 9DB310 802442F0 8E02000C */  lw        $v0, 0xc($s0)
/* 9DB314 802442F4 0C0B1EAF */  jal       get_variable
/* 9DB318 802442F8 8C450000 */   lw       $a1, ($v0)
/* 9DB31C 802442FC 2442FFFF */  addiu     $v0, $v0, -1
/* 9DB320 80244300 000218C0 */  sll       $v1, $v0, 3
/* 9DB324 80244304 00621823 */  subu      $v1, $v1, $v0
/* 9DB328 80244308 00031880 */  sll       $v1, $v1, 2
/* 9DB32C 8024430C 3C048025 */  lui       $a0, 0x8025
/* 9DB330 80244310 00832021 */  addu      $a0, $a0, $v1
/* 9DB334 80244314 8C84279C */  lw        $a0, 0x279c($a0)
/* 9DB338 80244318 00041140 */  sll       $v0, $a0, 5
/* 9DB33C 8024431C 3C018025 */  lui       $at, 0x8025
/* 9DB340 80244320 AC2429B4 */  sw        $a0, 0x29b4($at)
/* 9DB344 80244324 3C038008 */  lui       $v1, 0x8008
/* 9DB348 80244328 00621821 */  addu      $v1, $v1, $v0
/* 9DB34C 8024432C 946378F8 */  lhu       $v1, 0x78f8($v1)
/* 9DB350 80244330 AE040088 */  sw        $a0, 0x88($s0)
/* 9DB354 80244334 30630004 */  andi      $v1, $v1, 4
/* 9DB358 80244338 0003182B */  sltu      $v1, $zero, $v1
/* 9DB35C 8024433C AE030084 */  sw        $v1, 0x84($s0)
/* 9DB360 80244340 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9DB364 80244344 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DB368 80244348 24020002 */  addiu     $v0, $zero, 2
/* 9DB36C 8024434C 03E00008 */  jr        $ra
/* 9DB370 80244350 27BD0018 */   addiu    $sp, $sp, 0x18
/* 9DB374 80244354 00000000 */  nop       
/* 9DB378 80244358 00000000 */  nop       
/* 9DB37C 8024435C 00000000 */  nop       
