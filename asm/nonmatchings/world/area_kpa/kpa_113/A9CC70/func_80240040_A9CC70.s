.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240040_A9CC70
/* A9CC70 80240040 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A9CC74 80240044 AFB00010 */  sw        $s0, 0x10($sp)
/* A9CC78 80240048 0080802D */  daddu     $s0, $a0, $zero
/* A9CC7C 8024004C AFBF0014 */  sw        $ra, 0x14($sp)
/* A9CC80 80240050 8E02000C */  lw        $v0, 0xc($s0)
/* A9CC84 80240054 0C0B1EAF */  jal       get_variable
/* A9CC88 80240058 8C450000 */   lw       $a1, ($v0)
/* A9CC8C 8024005C 0040302D */  daddu     $a2, $v0, $zero
/* A9CC90 80240060 3C058016 */  lui       $a1, 0x8016
/* A9CC94 80240064 84A5A550 */  lh        $a1, -0x5ab0($a1)
/* A9CC98 80240068 3C048011 */  lui       $a0, %hi(gPlayerStatus)
/* A9CC9C 8024006C 2484EFC8 */  addiu     $a0, $a0, %lo(gPlayerStatus)
/* A9CCA0 80240070 10A60004 */  beq       $a1, $a2, .L80240084
/* A9CCA4 80240074 24020014 */   addiu    $v0, $zero, 0x14
/* A9CCA8 80240078 808300B4 */  lb        $v1, 0xb4($a0)
/* A9CCAC 8024007C 10620006 */  beq       $v1, $v0, .L80240098
/* A9CCB0 80240080 00000000 */   nop      
.L80240084:
/* A9CCB4 80240084 8C820014 */  lw        $v0, 0x14($a0)
/* A9CCB8 80240088 3C03FFFF */  lui       $v1, 0xffff
/* A9CCBC 8024008C 00431024 */  and       $v0, $v0, $v1
/* A9CCC0 80240090 10400005 */  beqz      $v0, .L802400A8
/* A9CCC4 80240094 00000000 */   nop      
.L80240098:
/* A9CCC8 80240098 0C039769 */  jal       set_action_state
/* A9CCCC 8024009C 0000202D */   daddu    $a0, $zero, $zero
/* A9CCD0 802400A0 0809003A */  j         .L802400E8
/* A9CCD4 802400A4 AE000084 */   sw       $zero, 0x84($s0)
.L802400A8:
/* A9CCD8 802400A8 54A6000F */  bnel      $a1, $a2, .L802400E8
/* A9CCDC 802400AC AE000084 */   sw       $zero, 0x84($s0)
/* A9CCE0 802400B0 808300B4 */  lb        $v1, 0xb4($a0)
/* A9CCE4 802400B4 24020014 */  addiu     $v0, $zero, 0x14
/* A9CCE8 802400B8 10620005 */  beq       $v1, $v0, .L802400D0
/* A9CCEC 802400BC 24020001 */   addiu    $v0, $zero, 1
/* A9CCF0 802400C0 10620003 */  beq       $v1, $v0, .L802400D0
/* A9CCF4 802400C4 24020002 */   addiu    $v0, $zero, 2
/* A9CCF8 802400C8 54620008 */  bnel      $v1, $v0, .L802400EC
/* A9CCFC 802400CC AE000084 */   sw       $zero, 0x84($s0)
.L802400D0:
/* A9CD00 802400D0 8C820004 */  lw        $v0, 4($a0)
/* A9CD04 802400D4 30420001 */  andi      $v0, $v0, 1
/* A9CD08 802400D8 54400003 */  bnel      $v0, $zero, .L802400E8
/* A9CD0C 802400DC AE000084 */   sw       $zero, 0x84($s0)
/* A9CD10 802400E0 24020001 */  addiu     $v0, $zero, 1
/* A9CD14 802400E4 AE020084 */  sw        $v0, 0x84($s0)
.L802400E8:
/* A9CD18 802400E8 24020002 */  addiu     $v0, $zero, 2
.L802400EC:
/* A9CD1C 802400EC 8FBF0014 */  lw        $ra, 0x14($sp)
/* A9CD20 802400F0 8FB00010 */  lw        $s0, 0x10($sp)
/* A9CD24 802400F4 03E00008 */  jr        $ra
/* A9CD28 802400F8 27BD0018 */   addiu    $sp, $sp, 0x18
