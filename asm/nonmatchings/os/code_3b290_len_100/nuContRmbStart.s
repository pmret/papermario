.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuContRmbStart
/* 3B290 8005FE90 00041080 */  sll       $v0, $a0, 2
/* 3B294 8005FE94 00441021 */  addu      $v0, $v0, $a0
/* 3B298 8005FE98 00021040 */  sll       $v0, $v0, 1
/* 3B29C 8005FE9C 3C01800B */  lui       $at, 0x800b
/* 3B2A0 8005FEA0 00220821 */  addu      $at, $at, $v0
/* 3B2A4 8005FEA4 90221D47 */  lbu       $v0, 0x1d47($at)
/* 3B2A8 8005FEA8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 3B2AC 8005FEAC 30420080 */  andi      $v0, $v0, 0x80
/* 3B2B0 8005FEB0 1440000B */  bnez      $v0, .L8005FEE0
/* 3B2B4 8005FEB4 AFBF0030 */   sw       $ra, 0x30($sp)
/* 3B2B8 8005FEB8 24020003 */  addiu     $v0, $zero, 3
/* 3B2BC 8005FEBC A3A20016 */  sb        $v0, 0x16($sp)
/* 3B2C0 8005FEC0 27A20010 */  addiu     $v0, $sp, 0x10
/* 3B2C4 8005FEC4 A3A40020 */  sb        $a0, 0x20($sp)
/* 3B2C8 8005FEC8 24040302 */  addiu     $a0, $zero, 0x302
/* 3B2CC 8005FECC A7A50010 */  sh        $a1, 0x10($sp)
/* 3B2D0 8005FED0 27A50020 */  addiu     $a1, $sp, 0x20
/* 3B2D4 8005FED4 A7A60012 */  sh        $a2, 0x12($sp)
/* 3B2D8 8005FED8 0C00B3CA */  jal       nuSiSendMesg
/* 3B2DC 8005FEDC AFA20028 */   sw       $v0, 0x28($sp)
.L8005FEE0:
/* 3B2E0 8005FEE0 8FBF0030 */  lw        $ra, 0x30($sp)
/* 3B2E4 8005FEE4 03E00008 */  jr        $ra
/* 3B2E8 8005FEE8 27BD0038 */   addiu    $sp, $sp, 0x38
/* 3B2EC 8005FEEC 00000000 */  nop       
