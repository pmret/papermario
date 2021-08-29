.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B88_ECB888
/* ECB888 80241B88 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* ECB88C 80241B8C AFB00010 */  sw        $s0, 0x10($sp)
/* ECB890 80241B90 0080802D */  daddu     $s0, $a0, $zero
/* ECB894 80241B94 AFBF0014 */  sw        $ra, 0x14($sp)
/* ECB898 80241B98 8E02000C */  lw        $v0, 0xc($s0)
/* ECB89C 80241B9C 0C0B53A3 */  jal       dead_evt_get_variable
/* ECB8A0 80241BA0 8C450000 */   lw       $a1, ($v0)
/* ECB8A4 80241BA4 3C048009 */  lui       $a0, %hi(dead_gItemTable)
/* ECB8A8 80241BA8 2484D2C0 */  addiu     $a0, $a0, %lo(dead_gItemTable)
/* ECB8AC 80241BAC 00021940 */  sll       $v1, $v0, 5
/* ECB8B0 80241BB0 00642021 */  addu      $a0, $v1, $a0
/* ECB8B4 80241BB4 240300BB */  addiu     $v1, $zero, 0xbb
/* ECB8B8 80241BB8 14430003 */  bne       $v0, $v1, .L80241BC8
/* ECB8BC 80241BBC 24020002 */   addiu    $v0, $zero, 2
/* ECB8C0 80241BC0 080906F9 */  j         .L80241BE4
/* ECB8C4 80241BC4 AE0200A8 */   sw       $v0, 0xa8($s0)
.L80241BC8:
/* ECB8C8 80241BC8 94820018 */  lhu       $v0, 0x18($a0)
/* ECB8CC 80241BCC 30420080 */  andi      $v0, $v0, 0x80
/* ECB8D0 80241BD0 10400003 */  beqz      $v0, .L80241BE0
/* ECB8D4 80241BD4 24020001 */   addiu    $v0, $zero, 1
/* ECB8D8 80241BD8 080906F9 */  j         .L80241BE4
/* ECB8DC 80241BDC AE0200A8 */   sw       $v0, 0xa8($s0)
.L80241BE0:
/* ECB8E0 80241BE0 AE0000A8 */  sw        $zero, 0xa8($s0)
.L80241BE4:
/* ECB8E4 80241BE4 8FBF0014 */  lw        $ra, 0x14($sp)
/* ECB8E8 80241BE8 8FB00010 */  lw        $s0, 0x10($sp)
/* ECB8EC 80241BEC 24020002 */  addiu     $v0, $zero, 2
/* ECB8F0 80241BF0 03E00008 */  jr        $ra
/* ECB8F4 80241BF4 27BD0018 */   addiu    $sp, $sp, 0x18
