.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E270
/* 19670 8003E270 3C03800A */  lui       $v1, %hi(D_8009A5E0)
/* 19674 8003E274 8C63A5E0 */  lw        $v1, %lo(D_8009A5E0)($v1)
/* 19678 8003E278 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1967C 8003E27C 2C620006 */  sltiu     $v0, $v1, 6
/* 19680 8003E280 10400019 */  beqz      $v0, .L8003E2E8
/* 19684 8003E284 AFBF0010 */   sw       $ra, 0x10($sp)
/* 19688 8003E288 00031080 */  sll       $v0, $v1, 2
/* 1968C 8003E28C 3C01800A */  lui       $at, %hi(D_800985B8)
/* 19690 8003E290 00220821 */  addu      $at, $at, $v0
/* 19694 8003E294 8C2285B8 */  lw        $v0, %lo(D_800985B8)($at)
/* 19698 8003E298 00400008 */  jr        $v0
/* 1969C 8003E29C 00000000 */   nop
/* 196A0 8003E2A0 0C010F80 */  jal       func_80043E00
/* 196A4 8003E2A4 00000000 */   nop
/* 196A8 8003E2A8 0800F8BA */  j         .L8003E2E8
/* 196AC 8003E2AC 00000000 */   nop
/* 196B0 8003E2B0 0C010407 */  jal       func_8004101C
/* 196B4 8003E2B4 00000000 */   nop
/* 196B8 8003E2B8 0800F8BA */  j         .L8003E2E8
/* 196BC 8003E2BC 00000000 */   nop
/* 196C0 8003E2C0 0C010589 */  jal       func_80041624
/* 196C4 8003E2C4 00000000 */   nop
/* 196C8 8003E2C8 0800F8BA */  j         .L8003E2E8
/* 196CC 8003E2CC 00000000 */   nop
/* 196D0 8003E2D0 0C010BA5 */  jal       func_80042E94
/* 196D4 8003E2D4 00000000 */   nop
/* 196D8 8003E2D8 0800F8BA */  j         .L8003E2E8
/* 196DC 8003E2DC 00000000 */   nop
/* 196E0 8003E2E0 0C010B43 */  jal       func_80042D0C
/* 196E4 8003E2E4 00000000 */   nop
.L8003E2E8:
/* 196E8 8003E2E8 0C01163A */  jal       func_800458E8
/* 196EC 8003E2EC 00000000 */   nop
/* 196F0 8003E2F0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 196F4 8003E2F4 03E00008 */  jr        $ra
/* 196F8 8003E2F8 27BD0018 */   addiu    $sp, $sp, 0x18
