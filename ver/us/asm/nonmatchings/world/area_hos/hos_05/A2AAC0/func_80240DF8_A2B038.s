.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DF8_A2B038
/* A2B038 80240DF8 3C048007 */  lui       $a0, %hi(gGameStatusPtr)
/* A2B03C 80240DFC 8C84419C */  lw        $a0, %lo(gGameStatusPtr)($a0)
/* A2B040 80240E00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2B044 80240E04 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2B048 80240E08 908300A8 */  lbu       $v1, 0xa8($a0)
/* A2B04C 80240E0C 2C620005 */  sltiu     $v0, $v1, 5
/* A2B050 80240E10 10400003 */  beqz      $v0, .L80240E20
/* A2B054 80240E14 24620001 */   addiu    $v0, $v1, 1
/* A2B058 80240E18 0C00D994 */  jal       state_init_intro
/* A2B05C 80240E1C A08200A8 */   sb       $v0, 0xa8($a0)
.L80240E20:
/* A2B060 80240E20 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2B064 80240E24 24020001 */  addiu     $v0, $zero, 1
/* A2B068 80240E28 03E00008 */  jr        $ra
/* A2B06C 80240E2C 27BD0018 */   addiu    $sp, $sp, 0x18
