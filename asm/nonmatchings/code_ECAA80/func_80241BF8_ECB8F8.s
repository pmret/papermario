.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241BF8_ECB8F8
/* ECB8F8 80241BF8 2404005A */  addiu     $a0, $zero, 0x5a
/* ECB8FC 80241BFC 3C038024 */  lui       $v1, %hi(D_802465C8)
/* ECB900 80241C00 246365C8 */  addiu     $v1, $v1, %lo(D_802465C8)
/* ECB904 80241C04 240200DA */  addiu     $v0, $zero, 0xda
.L80241C08:
/* ECB908 80241C08 AC620000 */  sw        $v0, ($v1)
/* ECB90C 80241C0C 2463FFFC */  addiu     $v1, $v1, -4
/* ECB910 80241C10 2484FFFF */  addiu     $a0, $a0, -1
/* ECB914 80241C14 0481FFFC */  bgez      $a0, .L80241C08
/* ECB918 80241C18 2442FFFF */   addiu    $v0, $v0, -1
/* ECB91C 80241C1C 3C018024 */  lui       $at, %hi(D_802465CC)
/* ECB920 80241C20 AC2065CC */  sw        $zero, %lo(D_802465CC)($at)
/* ECB924 80241C24 03E00008 */  jr        $ra
/* ECB928 80241C28 24020002 */   addiu    $v0, $zero, 2
/* ECB92C 80241C2C 00000000 */  nop
