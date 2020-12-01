.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047B84
/* 22F84 80047B84 00041040 */  sll       $v0, $a0, 1
/* 22F88 80047B88 00441021 */  addu      $v0, $v0, $a0
/* 22F8C 80047B8C 00021080 */  sll       $v0, $v0, 2
/* 22F90 80047B90 00441023 */  subu      $v0, $v0, $a0
/* 22F94 80047B94 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 22F98 80047B98 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 22F9C 80047B9C 00021100 */  sll       $v0, $v0, 4
/* 22FA0 80047BA0 00622021 */  addu      $a0, $v1, $v0
/* 22FA4 80047BA4 80820068 */  lb        $v0, 0x68($a0)
/* 22FA8 80047BA8 1040000C */  beqz      $v0, .L80047BDC
/* 22FAC 80047BAC 90830068 */   lbu      $v1, 0x68($a0)
/* 22FB0 80047BB0 80820069 */  lb        $v0, 0x69($a0)
/* 22FB4 80047BB4 14400009 */  bnez      $v0, .L80047BDC
/* 22FB8 80047BB8 24020001 */   addiu    $v0, $zero, 1
/* 22FBC 80047BBC A0830069 */  sb        $v1, 0x69($a0)
/* 22FC0 80047BC0 8C830070 */  lw        $v1, 0x70($a0)
/* 22FC4 80047BC4 A082006B */  sb        $v0, 0x6b($a0)
/* 22FC8 80047BC8 2402000A */  addiu     $v0, $zero, 0xa
/* 22FCC 80047BCC A0800068 */  sb        $zero, 0x68($a0)
/* 22FD0 80047BD0 A080006A */  sb        $zero, 0x6a($a0)
/* 22FD4 80047BD4 A082006D */  sb        $v0, 0x6d($a0)
/* 22FD8 80047BD8 AC830074 */  sw        $v1, 0x74($a0)
.L80047BDC:
/* 22FDC 80047BDC 03E00008 */  jr        $ra
/* 22FE0 80047BE0 00000000 */   nop      
