.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel copy_world_hud_element_ref_to_battle
/* DB9B4 801452B4 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB9B8 801452B8 00A22824 */  and       $a1, $a1, $v0
/* DB9BC 801452BC 00822024 */  and       $a0, $a0, $v0
/* DB9C0 801452C0 00042080 */  sll       $a0, $a0, 2
/* DB9C4 801452C4 3C028015 */  lui       $v0, %hi(D_80156F60)
/* DB9C8 801452C8 00441021 */  addu      $v0, $v0, $a0
/* DB9CC 801452CC 8C426F60 */  lw        $v0, %lo(D_80156F60)($v0)
/* DB9D0 801452D0 00052880 */  sll       $a1, $a1, 2
/* DB9D4 801452D4 3C018015 */  lui       $at, %hi(D_80157460)
/* DB9D8 801452D8 00250821 */  addu      $at, $at, $a1
/* DB9DC 801452DC AC227460 */  sw        $v0, %lo(D_80157460)($at)
/* DB9E0 801452E0 03E00008 */  jr        $ra
/* DB9E4 801452E4 00000000 */   nop
