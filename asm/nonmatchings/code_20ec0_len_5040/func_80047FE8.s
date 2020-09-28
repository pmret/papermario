.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047FE8
/* 233E8 80047FE8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 233EC 80047FEC 00041040 */  sll       $v0, $a0, 1
/* 233F0 80047FF0 00441021 */  addu      $v0, $v0, $a0
/* 233F4 80047FF4 00021080 */  sll       $v0, $v0, 2
/* 233F8 80047FF8 00441023 */  subu      $v0, $v0, $a0
/* 233FC 80047FFC 3C03800A */  lui       $v1, 0x800a
/* 23400 80048000 8C630F44 */  lw        $v1, 0xf44($v1)
/* 23404 80048004 00021100 */  sll       $v0, $v0, 4
/* 23408 80048008 AFBF0010 */  sw        $ra, 0x10($sp)
/* 2340C 8004800C 00621821 */  addu      $v1, $v1, $v0
/* 23410 80048010 80620098 */  lb        $v0, 0x98($v1)
/* 23414 80048014 10400004 */  beqz      $v0, .L80048028
/* 23418 80048018 00000000 */   nop      
/* 2341C 8004801C 8C64009C */  lw        $a0, 0x9c($v1)
/* 23420 80048020 0C05123D */  jal       free_icon
/* 23424 80048024 A0600098 */   sb       $zero, 0x98($v1)
.L80048028:
/* 23428 80048028 8FBF0010 */  lw        $ra, 0x10($sp)
/* 2342C 8004802C 03E00008 */  jr        $ra
/* 23430 80048030 27BD0018 */   addiu    $sp, $sp, 0x18
