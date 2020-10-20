.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AD8
/* DB83E8 80240AD8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DB83EC 80240ADC AFB00010 */  sw        $s0, 0x10($sp)
/* DB83F0 80240AE0 0080802D */  daddu     $s0, $a0, $zero
/* DB83F4 80240AE4 AFBF0014 */  sw        $ra, 0x14($sp)
/* DB83F8 80240AE8 8E02000C */  lw        $v0, 0xc($s0)
/* DB83FC 80240AEC 0C0B1EAF */  jal       get_variable
/* DB8400 80240AF0 8C450000 */   lw       $a1, ($v0)
/* DB8404 80240AF4 00021140 */  sll       $v0, $v0, 5
/* DB8408 80240AF8 AE000084 */  sw        $zero, 0x84($s0)
/* DB840C 80240AFC 3C018008 */  lui       $at, 0x8008
/* DB8410 80240B00 00220821 */  addu      $at, $at, $v0
/* DB8414 80240B04 942278F8 */  lhu       $v0, 0x78f8($at)
/* DB8418 80240B08 30420040 */  andi      $v0, $v0, 0x40
/* DB841C 80240B0C 10400002 */  beqz      $v0, .L80240B18
/* DB8420 80240B10 24020001 */   addiu    $v0, $zero, 1
/* DB8424 80240B14 AE020084 */  sw        $v0, 0x84($s0)
.L80240B18:
/* DB8428 80240B18 8FBF0014 */  lw        $ra, 0x14($sp)
/* DB842C 80240B1C 8FB00010 */  lw        $s0, 0x10($sp)
/* DB8430 80240B20 24020002 */  addiu     $v0, $zero, 2
/* DB8434 80240B24 03E00008 */  jr        $ra
/* DB8438 80240B28 27BD0018 */   addiu    $sp, $sp, 0x18
/* DB843C 80240B2C 00000000 */  nop       
