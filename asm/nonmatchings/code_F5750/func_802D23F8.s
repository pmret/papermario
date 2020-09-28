.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D23F8
/* F6DA8 802D23F8 3C038011 */  lui       $v1, %hi(gPlayerActionState)
/* F6DAC 802D23FC 9063F07C */  lbu       $v1, %lo(gPlayerActionState)($v1)
/* F6DB0 802D2400 2C620003 */  sltiu     $v0, $v1, 3
/* F6DB4 802D2404 1440000D */  bnez      $v0, .L802D243C
/* F6DB8 802D2408 00031600 */   sll      $v0, $v1, 0x18
/* F6DBC 802D240C 00021E03 */  sra       $v1, $v0, 0x18
/* F6DC0 802D2410 2402000A */  addiu     $v0, $zero, 0xa
/* F6DC4 802D2414 10620009 */  beq       $v1, $v0, .L802D243C
/* F6DC8 802D2418 2402000B */   addiu    $v0, $zero, 0xb
/* F6DCC 802D241C 10620007 */  beq       $v1, $v0, .L802D243C
/* F6DD0 802D2420 2402000E */   addiu    $v0, $zero, 0xe
/* F6DD4 802D2424 10620005 */  beq       $v1, $v0, .L802D243C
/* F6DD8 802D2428 24020010 */   addiu    $v0, $zero, 0x10
/* F6DDC 802D242C 10620003 */  beq       $v1, $v0, .L802D243C
/* F6DE0 802D2430 2402001A */   addiu    $v0, $zero, 0x1a
/* F6DE4 802D2434 14620003 */  bne       $v1, $v0, .L802D2444
/* F6DE8 802D2438 00000000 */   nop      
.L802D243C:
/* F6DEC 802D243C 03E00008 */  jr        $ra
/* F6DF0 802D2440 24020001 */   addiu    $v0, $zero, 1
.L802D2444:
/* F6DF4 802D2444 03E00008 */  jr        $ra
/* F6DF8 802D2448 0000102D */   daddu    $v0, $zero, $zero
